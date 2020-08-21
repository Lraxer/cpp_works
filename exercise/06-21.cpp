#include <iostream>
using namespace std;

int ret_bigger(const int &num1, const int* nump) {
    return num1>*nump ? num1 : *nump;
}

int main() {
    int n = 5, p = 98;
    cout << ret_bigger(n, &p) << endl;
    return 0;
}