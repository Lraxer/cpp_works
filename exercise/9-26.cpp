#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> iv(begin(ia), end(ia));
    list<int> lst(begin(ia), end(ia));

    auto iterv = iv.begin();
    auto iterlst = lst.begin();

    while(iterv!=iv.end()) {
        if(!(*iterv%2)) {
            iterv = iv.erase(iterv);
        } else {
            iterv++;
        }
    }

    while(iterlst!=lst.end()) {
        if(*iterlst%2) {
            iterlst = lst.erase(iterlst);
        } else {
            iterlst++;
        }
    }

    for(const auto &i : iv) {
        cout << i << " ";
    }
    cout << endl;
    for(const auto &j : lst) {
        cout << j << " ";
    }
    cout << endl;

    return 0;
}