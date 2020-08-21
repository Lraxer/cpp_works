#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool upper_exist(const string &str) {
    for(auto sit=str.begin();sit!=str.end();sit++) {
        if(isupper(*sit)) {
            return true;
        }
    }
    return false;
}

void change_to_lower(string &str) {
    for(char &c : str) {
        if(isupper(c)) {
            c = tolower(c);
        }
    }
}

int main() {
    string str{"Hello World!"};
    if(upper_exist(str)) {
        change_to_lower(str);
    }
    cout << str << endl;
    return 0;
}