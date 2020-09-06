#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void countWord() {
    unordered_map<string, size_t> word_count;
    string word;
    while(cin >> word) {
        ++word_count[word];
    }
    for(const auto &w : word_count) {
        cout << w.first << " occours " << w.second << ( (w.second>1)?  " times." : " time.") << endl;
    }
}

int main() {
    countWord();
    return 0;
}