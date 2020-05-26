#include <iostream>
#include <vector>
using std::cout; using std::cin; using std::endl; using std::vector;

int main() {
    vector<int> numlist;
    int n;
    while(cin>>n) {
        numlist.push_back(n);
    }

    for(int t : numlist) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}