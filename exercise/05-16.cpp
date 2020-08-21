#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> va{0,1,1,2};
    vector<int> vb{0,1,1,2,3,5,8};
    int i=0;

    unsigned int short_len = (va.size()>vb.size()) ? vb.size() : va.size();
    for(;i<short_len;i++) {
        if(va[i]!=vb[i]) {
            break;
        }
    }
    if(i==short_len) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}