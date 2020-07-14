#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool isEqual(const vector<int> &vi, const list<int> &li) {
    vector<int>::const_iterator itvb = vi.cbegin();
    vector<int>::const_iterator itve = vi.cend();
    list<int>::const_iterator itlb = li.cbegin();
    list<int>::const_iterator itle = li.cend();

    while(itvb!=itve && itlb!=itle) {
        if(*itvb!=*itlb) {
            return false;
        }
        itvb++;
        itlb++;
    }
    if(itvb!=itve || itlb!=itle) {
        return false;
    } else {
        return true;
    }
}