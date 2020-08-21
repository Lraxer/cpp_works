#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool chMoreThan4(const string &str) {
    return str.size()>=5;
}

int main() {
    vector<string> strvec{"21", "321", "4231", "5kljq", "asiofjsfjlaf", "q353lksdf", "gdfjgfjkvbnjkvnfsdvndkngjgk"};
    auto end_ch = partition(strvec.begin(), strvec.end(), chMoreThan4);
    for(auto it=strvec.begin();it!=end_ch;it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}