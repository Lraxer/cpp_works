#include <iostream>
#include <string>
#include <memory>
#include <cstring>

using namespace std;

int main() {
    string s1;
    cin >> s1;

    char *cs = new char [s1.size()+1];
    strcpy(cs, s1.c_str());

    cout << cs << endl;

    delete [] cs;
    return 0;
}