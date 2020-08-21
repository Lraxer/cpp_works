#include <iostream>
using std::cout; using std::cin; using std::endl;

int main() {
    int a[5] = {1,2,3,4,5};
    int *p = a;
    for(int i=0;i<5;i++) {
        *(p+i) = 0;
    }
    for(int n : a) {
        cout << n << " " ;
    }
    cout << endl;

    return 0;
}