#include <iostream>
#include <string>
#include "07-23-24.h"

using namespace std;

int main() {
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    return 0;
}