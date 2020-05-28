#include <iostream>
#include <string>
#include <cstring>
using std::cout; using std::cin; using std::endl; using std::string;

int main() {
    string a("Oceandeep");
    string b("Oceansdeep");

    char as[] = "oceandeep";
    char bs[] = "oceansdeep";

    cout << (a==b) << " " << strcmp(as, bs) << endl;

    return 0;
}