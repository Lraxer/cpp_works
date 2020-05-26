#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

void replace_str(string str) {
    for(char &c: str) {
        // Note that c is a reference
        // char &c, auto &c have the same function
        c = 'X';
    }
    cout << str << endl;
}

int main() {
    string str = "xxxxxxxxxxxx";
    replace_str(str);
    return 0;
}