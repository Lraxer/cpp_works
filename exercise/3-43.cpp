#include <iostream>
using std::cout; using std::cin; using std::endl;

// void use_range_for(int ia[][4]) {
//     for(auto &row : ia) {
//         ;
//     }
// }

void use_subscript(int ia[][4]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            cout << ia[i][j] << " ";
        }
    }
    cout << endl;
}

void use_pointer(int ia[][4]) {
    for(int (*p)[4]=ia;p!=ia+3;p++) {
        for(int *q=*p;q!=*p+4;q++) {
            cout << *q << " ";
        }
    }
    cout << endl;
}

int main() {
    int ia[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // Error occurs while in a function
    for(int (&i)[4] : ia) {
        for(int j : i) {
            cout << j << " ";
        }
    }
    cout << endl;

    use_subscript(ia);
    use_pointer(ia);

    return 0;
}