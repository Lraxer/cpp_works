#include <iostream>
using namespace std;

int fun() {
    static int i=0;
    return i++;
}

int main() {
    cout << fun() << endl;
    cout << fun() << endl;
    cout << fun() << endl;
    return 0;
}