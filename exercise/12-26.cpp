#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {
    // int n;
    // string *const p = new string[n];
    // string s;
    // string *q = p;
    // while(cin>>s && q!=p+n) {
    //     *q++ = s;
    // }
    // const size_t size = q-p;

    // delete [] p;

    int n=15;
    allocator<string> alloc;
    // string *const p = alloc.allocate(n);
    auto const p = alloc.allocate(n);
    string s;
    string *q = p;
    while(cin>>s && q!=p+n) {
        // q position behind the last element
        alloc.construct(q++, s);
    }
    const size_t size = q-p;

    for(size_t i=0;i<size;i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    while(q!=p) {
        // q=q-1, then destory q
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);

    return 0;
}