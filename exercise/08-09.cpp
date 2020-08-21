#include <iostream>
#include <sstream>
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
    istringstream istr("hello");
    test(istr);
    return 0;
}