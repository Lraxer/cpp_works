#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    // 1
    if(str1!=str2) {
        string tmp = str1>str2 ? str1 : str2;
        cout << "The larger string is: " << tmp << endl;
    } else {
        cout << "Same string" << endl;
    }

    // 2
    // if(str1.size()!=str2.size()) {
    //     string tmp = str1.size()>str2.size() ? str1 : str2;
    //     cout << "The longer string is: " << tmp << endl;
    // } else {
    //     cout << "Length of strings are equal" << endl;
    // }

    return 0;
}