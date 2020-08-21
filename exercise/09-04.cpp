#include <iostream>
#include <vector>

using namespace std;

bool searchValue(vector<int>::const_iterator& vbegin, vector<int>::const_iterator& vend, const int& value) {
    while(vbegin != vend) {
        if(*vbegin==value) {
            return true;
        }
        ++vbegin;
    }
    return false;
}