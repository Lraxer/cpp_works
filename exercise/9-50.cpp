#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> vsi{"2", "3", "6"};
    vector<string> vsd{"2.5", "3.4", "4.1"};

    int isum = 0;
    double dsum = 0.0;

    for(const auto &i : vsi) {
        isum+=stoi(i);
    }
    for(const auto &j : vsd) {
        dsum+=stod(j);
    }

    cout << isum << " " << dsum << endl;

    return 0;
}