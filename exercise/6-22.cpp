#include <iostream>
using namespace std;

void swap_pointer(int* (&a), int* (&b)) {
    int* tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int v1 = 5, v2 = 10;
    int *a = &v1, *b = &v2;
    swap_pointer(a, b);
    cout << *a << " " << *b << endl;

    return 0;
}