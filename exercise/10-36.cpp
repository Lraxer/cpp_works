#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    list<int> lst{2,4,0,6,0,7,3,0,5,8};
    auto rit = find(lst.crbegin(), lst.crend(), 0);
    cout << distance(lst.cbegin(), prev(rit.base())) << endl;
    return 0;
}