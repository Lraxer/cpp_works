#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main() {
    vector<int> vec{1,1,2,3,5,8,13,5,13,14,15,16,16,19};
    list<int> lst;
    // sort vector first
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    for(auto &i : lst) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}