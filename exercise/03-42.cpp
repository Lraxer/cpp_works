#include <iostream>
#include <vector>
#include <iterator>
using std::cout; using std::cin; using std::endl; using std::vector; using std::begin; using std::end;

int main() {
    vector<int> a{1,2,3,4,5,6,7,8};
    int b[8];
    for(int i=0;i<8;i++) {
        b[i] = a[i];
    }
    for(int* j=begin(b);j!=end(b);j++) {
        cout << *j << " ";
    }
    cout << endl;
    return 0;
}