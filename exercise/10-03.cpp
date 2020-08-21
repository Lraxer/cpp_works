#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<double> numvec{1,2,3,4.5,5,6,7,8,9,10};
    cout << accumulate(numvec.cbegin(), numvec.cend(), 0) << endl;
    return 0;
}