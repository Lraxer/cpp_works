#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr{
friend void swap(HasPtr &lhs, HasPtr &rhs);
friend void printout(const HasPtr &hp);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp):
        ps(new std::string(*(hp.ps))), i(hp.i) { }
    HasPtr& operator= (const HasPtr &hp);
    bool operator< (const HasPtr &hp) const;
    ~HasPtr();
private:
    std::string *ps;
    int i;
};

inline HasPtr& HasPtr::operator= (const HasPtr &hp) {
    auto newps = new std::string(*hp.ps);
    delete ps;
    ps = newps;
    i = hp.i;
    return *this;
}

inline bool HasPtr::operator< (const HasPtr &hp) const {
    return *ps<*hp.ps;
}

HasPtr::~HasPtr() {
    delete ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    cout << "swap" << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

void printout(const HasPtr &hp) {
    cout << *hp.ps << endl;
}


int main() {
    string tmp;
    vector<HasPtr> vechp;
    while(cin>>tmp) {
        vechp.push_back(HasPtr(tmp));
    }
    // if elements number is more than 16, swap will be called
    sort(vechp.begin(), vechp.end());

    for(const auto &i : vechp) {
        printout(i);
    }

    return 0;
}