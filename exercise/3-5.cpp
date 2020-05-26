#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

void cat_string(string str1, string str2) {
    string newstr = str1 + str2;
    string newstr2 = str1+" "+str2;
    cout << "Concatenated string: " << newstr << endl;
    cout << newstr2 << endl;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cat_string(str1, str2);
    return 0;
}