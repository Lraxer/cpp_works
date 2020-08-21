#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list <string> lst = {"123", "234", "234", "345"};
    cout << count(lst.cbegin(), lst.cend(), "234") << endl;

    return 0;
}