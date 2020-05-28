#include <iostream>
#include <cstring>
using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    char as[] = "I once had a girl, ";
    char bs[] = "or should I say, she once had me.";
    char cs[100];
    strcat(as, bs);
    strcpy(cs, as);
    for(int i=0;i<strlen(cs);i++) {
        cout << cs[i];
    }
    cout << endl;
    return 0;
}