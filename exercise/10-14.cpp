#include <iostream>
using namespace std;

int main() {
    auto fsum = [] (int a, int b) { return a+b; };
    cout << fsum(3,5) << endl;
    return 0;
}