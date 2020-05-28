#include <iostream>
#include <vector>
using std::cout; using std::cin; using std::endl; using std::vector;

void modify(int a[], int asize) {
    for(int i=0;i<asize;i++) {
        a[i] = i;
    }
}

void copy_array(int a[], int b[], int asize) {
    for(int i=0;i<asize;i++) {
        b[i] = a[i];
    }
}

void modify_vector(vector<int> &a) {
    for(int i=0;i<a.size();i++) {
        a[i] = i;
    }
}

void copy_vector(vector<int> a, vector<int> &b) {
    for(auto ita=a.begin(), itb = b.begin(); ita!=a.end(); ita++, itb++) {
        *itb = *ita;
    }
}

int main() {
    int a[10] = {};
    int b[10] = {};
    modify(a, 10);
    copy_array(a, b, 10);

    vector<int> va(10);
    vector<int> vb(10);

    modify_vector(va);
    copy_vector(va, vb);

    for(int i=0;i<10;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0;i<10;i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    for(int i=0;i<10;i++) {
        cout << va[i] << " ";
    }
    cout << endl;
    for(int i=0;i<10;i++) {
        cout << vb[i] << " ";
    }
    cout << endl;

    return 0;

}