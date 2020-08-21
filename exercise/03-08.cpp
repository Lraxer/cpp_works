#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

void use_while(string str) {
    unsigned i=0;
    while(i<str.size()) {
        str[i] = 'X';
        i++;
    }
    cout << "Use while statement" << endl;
    cout << str << endl;
}

void use_traditional_for(string str) {
    for(unsigned i=0;i<str.size();i++) {
        str[i] = 'X';
    }
    cout << "Use traditional for statement" << endl;
    cout << str << endl;
}

int main() {
    string str = "sdkjfgoiserj'";
    use_while(str);
    use_traditional_for(str);
    return 0;
}