#include <iostream>
using std::cout; using std::cin; using std::endl;

void modify(int a[], int asize) {
    for(int i=0;i<asize;i++) {
        a[i] = i;
    }
}

int main() {
    int a[10] = {};
    modify(a, 10);

    for(int i : a) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}