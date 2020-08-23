#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz) {
    return s.size() <= sz;
}

int main() {
    vector<int> vecnum{4,0,2,8,3,4,1,1};
    string str("123456");
    auto it = find_if(vecnum.begin(), vecnum.end(), bind(check_size, str, _1));
    if(it!=vecnum.end()) {
        cout << *it << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}