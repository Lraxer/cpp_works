#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);

    // act as values
    StrBlob(const StrBlob &stb);
    StrBlob& operator= (const StrBlob &stb);

    size_type size() const { return data->size();};
    bool empty() const { return data->empty();};

    void push_back(const string &t) { data->push_back(t);};
    void pop_back();

    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

    // Provide interfaces 
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};


class StrBlobPtr {
friend bool isStrBlobPtrEqual(const StrBlobPtr& sbp1, const StrBlobPtr& sbp2);
public:
    StrBlobPtr(): curr(0) {};
    StrBlobPtr(StrBlob &a, size_t sz=0): wptr(a.data), curr(sz) {};
    string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlob::StrBlob(): data(std::make_shared<vector<string>>()) {};

StrBlob::StrBlob(initializer_list<string> il): data(std::make_shared<vector<string>>(il)) {}

StrBlob::StrBlob(const StrBlob &stb): data(make_shared<vector<string>>()) {}

StrBlob& StrBlob::operator= (const StrBlob &stb) {
    data = make_shared<vector<string>>(*stb.data);
    return *this;
}

void StrBlob::check(size_type i, const string &msg) const {
    if(i>=data->size()) {
        throw out_of_range(msg);
    }
}

string& StrBlob::front() {
    check(0, "back on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const {
    check(0, "back on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}


shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if(!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if(i>=ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool isStrBlobPtrEqual(const StrBlobPtr& sbp1, const StrBlobPtr& sbp2) {
    auto s1 = sbp1.wptr.lock(), s2 = sbp2.wptr.lock();
    if(s1==s2) {
        return (!s1 || sbp1.curr==sbp2.curr);
    } else {
        return false;
    }
}
