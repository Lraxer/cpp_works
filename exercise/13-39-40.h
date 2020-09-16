#ifndef _13_39_40_H_
#define _13_39_40_H_

#include <string>
#include <memory>
#include <initializer_list>

using std::allocator; using std::string; using std::pair; using std::size_t;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const initializer_list<string>&);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const string&);
    size_t size() const { return first_free-elements; }
    size_t capacity() const { return cap-elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }

    void reserve(const size_t n);
    void resize(const size_t, const string &);
private:
    static allocator<string> alloc;
    // Pointer to the first element
    string *elements;
    // Pointer to the first free element in allocated space
    string *first_free;
    // Pointer to one past the end of the allocated space
    string *cap;

    // check
    void chk_n_alloc();
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
};

#endif