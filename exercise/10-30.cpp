#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

void readSortNum() {
    istream_iterator<int> numin(cin), eof;
    ostream_iterator<int> numout(cout, " ");
    vector<int> numvec;
    while(numin!=eof) {
        numvec.push_back(*numin++);
    }
    // 升序
    sort(numvec.begin(), numvec.end());
    // 降序
    // sort(numvec.begin(), numvec.end(),
    //     [] (const int &a, const int &b) {return a>b;});
    copy(numvec.begin(), numvec.end(), numout);
}

int main() {
    readSortNum();
    return 0;
}