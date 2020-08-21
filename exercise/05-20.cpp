#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, tmp;
    while(cin>>str) {
        if(str==tmp) {
            cout << str << endl;
            break;
        }
        tmp = str;
    }

    return 0;
}