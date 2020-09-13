#include <iostream>
#include <string>

using namespace std;

class HasPtr{
friend void printout(const HasPtr&);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp):
        ps(new std::string(*(hp.ps))), i(hp.i) { }
    HasPtr& operator= (const HasPtr &hp);
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

HasPtr::~HasPtr() {
    delete ps;
}

void printout(const HasPtr &hp) {
    cout << *hp.ps << endl;
}


int main() {
    HasPtr hp1("123"), hp2("456"), hp3("678");
    hp1 = hp3;
    printout(hp1);
    printout(hp2);
    printout(hp3);
    return 0;
}