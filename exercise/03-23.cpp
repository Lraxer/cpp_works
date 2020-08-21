#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::vector;

int main() {
    vector<int> numlist;
    for(int i=0;i<10;i++) {
        numlist.push_back(i);
    }

    for(int n : numlist) {
        cout << n << " ";
    }
    cout << endl;

    for(auto it=numlist.begin();it!=numlist.end();it++) {
        *it *= 2;
    }

    for(int n : numlist) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}