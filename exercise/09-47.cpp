#include <iostream>
#include <string>
using namespace std;

int main() {
    string st("ab2c3d7R4E6");
    string numbers("1234567890");

    for(size_t i=0;(i=st.find_first_of(numbers, i))!=string::npos;i++) {
        cout << st[i] << " ";
    }
    cout << endl;

    for(size_t j=0;(j=st.find_first_not_of(numbers, j))!=string::npos;j++) {
        cout << st[j] << " ";
    }
    cout << endl;

    return 0;
}