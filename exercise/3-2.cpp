#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

void get_a_line() {
    string str;
    getline(cin, str);
    cout << "The line is: " << endl;
    cout << str << endl;
}

void get_words() {
    string str;
    while(cin>>str) {
        cout << "Get a word: " << str << endl;
    }
}


int main() {
    cout << "Input a line" << endl;
    get_a_line();
    cout << "Input some words" << endl;
    get_words();
    return 0;
}
