#ifndef _13_44_H_
#define _13_44_H_

#include <memory>
#include <utility>
#include <iostream>

using std::allocator; using std::cout; using std::cin; using std::endl; using std::pair;
using std::uninitialized_copy; using std::size_t; using std::uninitialized_fill_n;
using std::ostream; using std::istream;

class String {
friend String operator+(const String&, const String&);
friend ostream& operator<<(ostream&, const String&);
friend istream& operator>>(istream&, String&);
public:
    String();
    String(const char*);
    String(const size_t, const char);
    String(const String&);
    String& operator=(const String&);
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;
    ~String();
    size_t size() const;
    char* begin() const;
    char* end() const;
private:
    void free();
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    static allocator<char> alloc;
    char *start;
    char *tail;
};

// Define static variables
allocator<char> String::alloc;

inline String::String(): String("") {}

String::String(const char* sBegin) {
    // Remove const
    char *sEnd = const_cast<char*>(sBegin);
    while(*sEnd) {
        ++sEnd;
    }
    // if sBegin=='\0'
    if(sBegin==sEnd) {
        ++sEnd;
    }
    auto newdata = alloc_n_copy(sBegin, sEnd);
    start = newdata.first;
    tail = newdata.second;
}

String::String(const size_t sz, const char c) {
    if(sz<=0) {
        String("");
        return;
    }
    char *data = alloc.allocate(sz+1);
    char *endData = uninitialized_fill_n(data, sz, c);
    alloc.construct(endData, '\0');

    start = data;
    tail = endData;
}

String::String(const String &str) {
    auto newdata = alloc_n_copy(str.begin(), str.end());
    start = newdata.first;
    tail = newdata.second;
}

String& String::operator=(const String &str) {
    // FIXME May have a better solution, especially when this->size() >= str.size()
    auto newdata = alloc_n_copy(str.begin(), str.end());
    free();
    start = newdata.first;
    tail = newdata.second;
    return *this;
}

// Move constructor
inline String::String(String &&str) noexcept : start(str.start), tail(str.tail){
    str.start = str.tail = nullptr;
}

// Move assignment
String& String::operator=(String &&str) noexcept {
    // check self-assignment
    if(this!=&str) {
        free();
        start = str.start;
        tail = str.tail;
        str.start = str.tail = nullptr;
    }
    return *this;
}

inline String::~String() {
    free();
}

inline size_t String::size() const {
    if(*start=='\0') {
        // if string is "", String saves as '\0\0'
        return 0;
    } else {
        return tail-start;
    }
}

inline char* String::begin() const {
    return start;
}

inline char* String::end() const {
    return tail;
}

pair<char*, char*> String::alloc_n_copy(const char* sBegin, const char* sEnd) {
    // sEnd point to '\0' when sBegin!='\0'
    // sEnd point atfter '\0' when sBegin=='\0'
    char *data = alloc.allocate(sEnd-sBegin+1);
    char *endData = uninitialized_copy(sBegin, sEnd, data);
    alloc.construct(endData, '\0');
    return {data, endData};
}

void String::free() {
    if(start) {
        for(auto p=tail;p!=start;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(start, tail-start);
    }
}

String operator+(const String& s1, const String& s2) {
    String str;
    size_t newsize = s1.size()+s2.size();
    char *data = String::alloc.allocate(newsize+1);
    char *midData = uninitialized_copy(s1.begin(), s1.end(), data);
    char *endData = uninitialized_copy(s2.begin(), s2.end(), midData);
    String::alloc.construct(endData, '\0');

    str.start = data;
    str.tail = endData;

    return str;
}

ostream& operator<<(ostream &os, const String &str) {
    auto p = str.begin();
    while(p!=str.end()) {
        os << *p;
        ++p;
    }
    return os;
}

istream& operator>>(istream &is, String &str) {
    char *buf = new char[4096];
    is >> buf;
    if(is) {
        String tmp(buf);
        str = std::move(tmp);
    } else {
        str = String();
    }

    delete[] buf;
    return is;
}

#endif