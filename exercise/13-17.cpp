#include <iostream>
#include <string>
using namespace std;

class numbered {
public:
    numbered() { mysn = count++;}
    // numbered(const numbered &n1): mysn(count++) { }
    int mysn;
private:
    static int count;
};

int numbered::count = 0;

void f(numbered s) {
    cout << s.mysn << endl;
}
// void f(const numbered &s) {
//     cout << s.mysn << endl;
// }

int main() {
    numbered a, b=a, c=b;
    f(a); f(b); f(c);
    return 0;
}