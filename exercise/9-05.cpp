#include <iostream>
#include <vector>
using namespace std;

vector<int>::const_iterator searchValue(vector<int>::const_iterator& vbegin, vector<int>::const_iterator& vend, const int& value) {
    while(vbegin!=vend) {
        if(*vbegin==value) {
            return vbegin;
        }
        vbegin++;
    }
    return vend;
}