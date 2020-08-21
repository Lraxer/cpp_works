#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::vector;

int main() {
    vector<unsigned> score(11,0);
    unsigned grade;
    while(cin>>grade) {
        // if use ++, remember that ++ has a higher priority than *
        *(score.begin()+grade/10) += 1;
    }

    for(unsigned n : score) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}