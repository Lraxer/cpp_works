#include <iostream>
#include <vector>
using namespace std;

int addnum(int a, int b) {
    return a+b;
}

int subnum(int a, int b) {
    return a-b;
}

int mulnum(int a, int b) {
    return a*b;
}

int divnum(int a, int b) {
    return a/b;
}

int main() {
    vector<int(*)(int, int)> newvt;
    int (*p1)(int, int) = &addnum;
    int a = 5, b = 3;

    newvt.push_back(p1);
    p1 = &subnum;
    newvt.push_back(p1);
    p1 = &mulnum;
    newvt.push_back(p1);
    p1 = &divnum;
    newvt.push_back(p1);

    for(int(* &p)(int, int) : newvt) {
        cout << p(a,b) << endl;
    }

    return 0;
}