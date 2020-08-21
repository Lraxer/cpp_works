#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

void print_nei_sum(vector<int> numlist) {
    for(unsigned i=0;i<numlist.size()-1;i++) {
        cout << numlist[i]+numlist[i+1] << " ";
    }
    cout << endl;
}

void print_headtail_sum(vector<int> numlist) {
    unsigned length = numlist.size();
    for(unsigned i=0;i<length/2;i++) {
        cout << numlist[i]+numlist[length-1-i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numlist;
    int num;
    while(cin>>num) {
        numlist.push_back(num);
    }

    print_nei_sum(numlist);
    print_headtail_sum(numlist);

    return 0;
}