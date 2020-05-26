#include <iostream>
#include <string>
#include <cctype>
using std::cout; using std::cin; using std::endl; using std::string;

void remove_punc(string str) {
    for(char c: str) {
        if(!ispunct(c)){
            cout << c;
        }
    }
    cout << endl;
}

int main() {
    string str = "But do you know what I think? I think love is a touch and yet not a touch.";
    
    remove_punc(str);
    return 0;
}