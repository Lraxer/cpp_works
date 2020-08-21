#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numlist{1,2,3,4,5,6,7,8};
    for(int &n : numlist) {
        n = n%2==0 ? n : 2*n;
    }

    for(int n : numlist) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}