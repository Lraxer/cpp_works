#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numvec{1,2,3,4,5,6,7,8,9,0};

    // method 1
    list<int> lst1;
    copy(numvec.cbegin()+3, numvec.cbegin()+8, front_inserter(lst1));
    for_each(lst1.cbegin(), lst1.cend(), [] (const int &i) {cout << i << " ";});
    cout << endl;

    // method 2
    list<int> lst2(5);
    copy(numvec.cbegin()+3, numvec.cbegin()+8, lst2.rbegin());
    for_each(lst2.cbegin(), lst2.cend(), [] (const int &i) {cout << i << " ";});
    cout << endl;
    
    return 0;
}