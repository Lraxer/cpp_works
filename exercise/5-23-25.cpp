// 5-23, 5-25
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    try {
        if(b==0) {
            throw runtime_error("");
        }
        cout << a/b << endl;
    } catch(runtime_error err) {
        cout << err.what() << "Divisor is zero." << endl;
    }
    return 0;
}