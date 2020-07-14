#include <iostream>
#include <string>
using namespace std;

void strReplace2(string &s, const string &oldVal, const string &newVal) {
    for(size_t i=0;i!=s.size()-oldVal.size();) {
        if(oldVal==s.substr(i, oldVal.size())) {
            s = s.replace(i, oldVal.size(), newVal);
            i = i+newVal.size();
        } else {
            i++;
        }
    }
}

int main() {
    string s("To drive straight thru is a foolish, tho courageous act.");
    strReplace2(s, "thru", "through");
    strReplace2(s, "tho", "though");

    cout << s << endl;
    return 0;
}