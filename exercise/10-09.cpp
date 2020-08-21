#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &words) {
    for(auto &i : words) {
        cout << i << " " ;
    }
    cout << endl;
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    for(auto &i : words) {
        cout << i << " " ;
    }
    cout << endl;
    words.erase(end_unique, words.end());
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    for(auto &i : words) {
        cout << i << " " ;
    }
    cout << endl;

    return 0;
}