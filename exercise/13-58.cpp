#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Foo {
public:
    Foo()=delete;
    Foo(const vector<int> &newdata): data(newdata) {}
    Foo(const Foo &f) : data(f.data) {}
    Foo sorted() &&;
    Foo sorted() const &;
    void showData();
private:
    vector<int> data;
};

Foo Foo::sorted() && {
    cout << "Foo::sorted() &&" << endl;
    sort(data.begin(), data.end());
    return *this;
}


Foo Foo::sorted() const & {
    cout << "Foo::sorted() const &" << endl;
    return Foo(*this).sorted();
}

void Foo::showData() {
    for(const auto &i : data) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> newdata = {5,8,2,4,9,7,0,1,3,6};
    Foo newf(newdata);

    Foo newf2(newf.sorted());
    newf2.showData();

    Foo newf3((std::move(newf)).sorted());
    newf3.showData();

    return 0;
}