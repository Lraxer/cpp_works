#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countNumValue(const vector<int> &numvec, const int &searnum) {
    return count(numvec.cbegin(), numvec.cend(), searnum);
}

int main() {
    vector <int> numvec = {1,2,3,4,5,6,7,7,7,6,5,4,0,1};
    cout << countNumValue(numvec, 7) << endl;
    return 0;
};