#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    do {
        string &s = (str1.size()<str2.size()) ? str1 : str2;
        cout << s << endl;
    } while(cin>>str1>>str2);

    return 0;
}