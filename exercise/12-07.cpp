#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void printInput(shared_ptr<vector<int>> &pv) {
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
    shared_ptr<vector<int>> pv = make_shared<vector<int>>();
    printInput(pv);
    return 0;
}