#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isShorter(const string &str1, const string &str2) {
    return str1.size() < str2.size();
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    for(auto &i : words) {
        cout << i << " ";
    }
    cout << endl;
    stable_sort(words.begin(), words.end(), isShorter);
    for(auto &i : words) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}