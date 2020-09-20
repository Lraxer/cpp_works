#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

#include "13-39-40.h"

using namespace std;

allocator<string> StrVec::alloc;

StrVec::StrVec(const initializer_list<string> &lst) {
    auto newdata = alloc_n_copy(lst.begin(), lst.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline StrVec& StrVec::operator=(const StrVec& rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline StrVec::~StrVec() {
    free();
}

inline void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(const size_t n) {
    if(capacity()>=n) {
        return ;
    }
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0;i!=size();i++) {
        alloc.construct(dest++, move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements+n;
}

void StrVec::resize(const size_t n, const string &str=string()) {
    if(n<0) {
        throw runtime_error("Parameter of StrVec::resize() must be greater than zero.");
    }
    if(n>capacity()) {
        reserve(n);
    }
    if(n>size()) {
        for(size_t i=size();i!=n;i++) {
            alloc.construct(first_free++, str);
        }
    } else {
        auto p = first_free;
        for(size_t i=size(); i!=n;i--) {
            alloc.destroy(--p);
        }
        alloc.deallocate(p, first_free-p);
        first_free = p;
    }
}


inline void StrVec::chk_n_alloc() {
    if(size() == capacity()) {
        reallocate();
    }
}

inline pair<string*, string*> StrVec::alloc_n_copy(const string*b, const string*e) {
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if(elements) {
        for (auto p=first_free;p!=elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap-elements);
    }
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2*size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0;i!=size();i++) {
        alloc.construct(dest++, move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements+newcapacity;
}