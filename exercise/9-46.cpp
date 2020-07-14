#include <iostream>
#include <string>
using namespace std;

string addPrefixSuffix2(const string &name, const string &prefix, const string &suffix) {
    string fullName(name);
    fullName.insert(0, prefix);
    fullName.insert(fullName.size(), " "+suffix);

    return fullName;
}

int main() {
    string name("Tony");
    cout << addPrefixSuffix2(name, "Mr.", "Jr.") << endl;
     
    return 0;
}