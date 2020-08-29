#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<pair<string, int>> pavec;
    string tmps;
    int tmpi;
    while(cin >> tmps >> tmpi) {
        // method 1
        pair<string, int> tmp_pair(tmps, tmpi);
        // method 2
        // pair<string, int> tmp_pair = {tmps, tmpi};
        // method 3
        // pair<string, int> tmp_pair = make_pair(tmps, tmpi);

        pavec.push_back(tmp_pair);
    }

    for(auto &i : pavec) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}