#include <iostream>
#include <vector>
using std::cout; using std::cin; using std::endl; using std::vector;

bool isArrayEqual(int a[], int b[], int arraySize) {
    int i;
    for(i=0;i<arraySize;i++) {
        if(a[i]!=b[i]) {
            return false;
        }
    }
    return true;
}

bool isVectorEqual(vector<int> va, vector<int> vb) {
    if(va==vb) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int a[5] = {1,2,3,4,5};
    int b[5] = {1,2,3,4,5};
    int c[5] = {1,2,2,3,6};

    vector<int> va{1,2,3,4,5,6,7};
    vector<int> vb{1,2,3,4,5,6,7};
    vector<int> vc{1,2,2,3,5,6,7};

    cout << isArrayEqual(a,b,5) << ", " << isArrayEqual(a,c,5) << ", " << isVectorEqual(va,vb) << ", " << isVectorEqual(va, vc) << endl;

    return 0;
}