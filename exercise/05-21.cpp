#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, tmp;
    while(cin>>str) {
        if(str==tmp&&isupper(str[0])) {
            cout << str << endl;
            break;
        }
        tmp = str;
    }
    return 0;
}