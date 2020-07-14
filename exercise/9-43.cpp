#include <iostream>
#include <string>
using namespace std;

void strReplace(string &s, const string &oldVal, const string &newVal) {
    for(auto iter=s.begin();iter!=s.end()-oldVal.size();) {
        if(oldVal==string(iter, iter+oldVal.size())) {
            iter = s.erase(iter, iter+oldVal.size());
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter = iter+newVal.size();
        } else {
            iter++;
        }
    }
}

int main() {
    string s("To drive straight thru is a foolish, tho courageous act.");
    strReplace(s, "thru", "through");
    strReplace(s, "tho", "though");

    cout << s << endl;
    return 0;
}