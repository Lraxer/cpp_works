#include <iostream>
using namespace std;

int main() {
    int t = 4;
    auto fsum = [t] (int a) { return a+t; };
    cout << fsum(2) << endl;

    return 0;
}