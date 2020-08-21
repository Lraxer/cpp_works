#include <iostream>
using namespace std;

int main() {
    int i = 4;
    double d = 3.3;
    i *= static_cast<int>(d);

    cout << i << endl;

    return 0;
}