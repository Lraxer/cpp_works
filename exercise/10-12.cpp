#include <iostream>
#include <vector>
#include <algorithm>
#include "D:\learn\c_cpp\cpp primer file\7\Sales_data.h"
using namespace std;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
    return sd1.isbn() < sd2.isbn();
}

void sortSDVector(vector<Sales_data> &sdvector) {
    sort(sdvector.begin(), sdvector.end(), compareIsbn);
}

int main() {
    vector<Sales_data> sdvector{Sales_data("a"), Sales_data("aa"), Sales_data("z"), Sales_data("aaa")};
    sortSDVector(sdvector);
    for(auto &i : sdvector) {
        cout << i.isbn() << " ";
    }
    cout << endl;
    return 0;
}