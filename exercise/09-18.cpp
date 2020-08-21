#include <iostream>
#include <string>
#include <deque>

using namespace std;

void readStrSave2Deque() {
    deque<string> qstr;
    string tmp;
    while(getline(cin, tmp)) {
        qstr.push_back(tmp);
    }

    for(auto iter=qstr.cbegin();iter!=qstr.cend();iter++) {
        cout << *iter << endl;
    }
}