#include <iostream>
#include <vector>
#include <new>

using namespace std;

void printInput(vector<int> *pv) {
    int tmp;
    while(cin>>tmp) {
        pv->push_back(tmp);
    }

    for(auto &i : *pv) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // c/c++ plugin of vscode tells me that 'new' has an error, but g++ can compile it.
    vector<int> *pv = new (nothrow) vector<int>;
    if(!pv) {
        return -1;
    }
    
    printInput(pv);

    delete pv;
    pv = nullptr;
    return 0;
}