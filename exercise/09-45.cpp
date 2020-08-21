#include <iostream>
#include <string>
using namespace std;

string addPrefixSuffix(const string &name, const string &prefix, const string &suffix) {
    string fullName(name);
    fullName.insert(fullName.begin(), prefix.begin(), prefix.end());
    fullName.append(" "+suffix);

    return fullName;
}

int main() {
    string name("Tony");
    cout << addPrefixSuffix(name, "Mr.", "Jr.") << endl;

    return 0;
}