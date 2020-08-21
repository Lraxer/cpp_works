#include <iostream>
#include <string>
using namespace std;

istream& test(istream& is) {
    string buf;
    while(is >> buf) {
        cout << buf << endl;
    }
    return is;
}

int main() {
    test(cin);
    return 0;
}