#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numvec{1,2,3,4,5,6,7,8,9};
    fill_n(numvec.begin(), numvec.size(), 0);
    for(const auto &i : numvec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}