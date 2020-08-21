#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl; using std::vector;

void print_nei_sum(vector<int> numlist) {
    for(auto it=numlist.begin();it!=numlist.end()-1;it++) {
        cout << *it+*(it+1) << " ";
    }
    cout << endl;
}

void print_headtail_sum(vector<int> numlist) {
    for(auto it=numlist.begin();it!=numlist.begin()+numlist.size()/2;it++) {
        auto tailit = numlist.begin()+(numlist.end()-it-1);
        cout << *it+*tailit << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numlist;
    int inputnum;
    while (cin>>inputnum)
    {
        numlist.push_back(inputnum);
    }
    print_nei_sum(numlist);
    print_headtail_sum(numlist);
    
    return 0;
}