#include <iostream>
#include <memory>
#include <string>
#include <cstring>

using namespace std;

void linkChar(const char *s1, const char *s2) {
    size_t len = strlen(s1) + strlen(s2) + 1;
    char *s3 = new char[len];
    strcpy(s3, s1);
    strcat(s3, s2);
    printf("%s\n", s3);

    delete [] s3;
}

void linkString(const string &s1, const string &s2) {
    char *s3 = new char[s1.size()+s2.size()+1];
    // c_str() converts string to const char*
    strcpy(s3, (s1+s2).c_str());
    // print char* string
    cout << s3 << endl;
    delete [] s3;
}

int main() {
    linkChar("123", "456");
    linkString("abc", "def");
    return 0;
}