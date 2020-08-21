#include <iostream>
#include <deque>
#include <list>

using namespace std;

void cp2Deque(const list<int> &lst, deque<int> &even, deque<int> &odd) {
    for(auto iter=lst.cbegin();iter!=lst.cend();iter++) {
        if((*iter)%2) {
            odd.push_back(*iter);
        } else {
            even.push_back(*iter);
        }
    }
}

int main() {
    list<int> lst{1,2,3,4,5,6,7,8,9};
    deque<int> even, odd;
    cp2Deque(lst, even, odd);

    for(auto &di : even) {
        cout << di << " ";
    }
    cout << endl;

    for(auto &di : odd) {
        cout << di << " ";
    }
    cout << endl;

    return 0;
}