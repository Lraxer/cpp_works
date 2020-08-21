#include <iostream>
#include <vector>
#include <iterator>
using std::cout; using std::cin; using std::endl; using std::vector; using std::begin; using std::end;

int main() {
    int a[] = {1,2,3,4,6};
    vector<int> va(begin(a), end(a));
    for(int n : va) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}