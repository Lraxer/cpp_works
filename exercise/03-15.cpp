#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

int main() {
    vector<string> strlist;
    string newstr;
    getline(cin, newstr);
    while(!newstr.empty()) {
        strlist.push_back(newstr);
        getline(cin, newstr);
    }

    for(string c : strlist) {
        cout << c << endl;
    }
    return 0;
}