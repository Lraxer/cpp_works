#include <iostream>
using namespace std;

class Point {
public:
    Point(): p(0) {};
    Point(int num): p(num) {};
    Point(const Point &pt): p(pt.p) {cout << "copy" << endl; };
private:
    int p;
};

Point global;
Point foo_bar(Point arg /* 1 */) {
    Point local = arg, *heap = new Point(global); // 2,3
    *heap = local;
    // the following statement uses copy constructor
    // new Point(global);
    // the following statement uses copy constructor
    // Point tmp(global);
    Point pa[4] = {local, *heap}; // 4, 5
    return *heap; // 6
}

int main() {
    Point arg(100);
    Point tmp = foo_bar(arg);
    return 0;
}