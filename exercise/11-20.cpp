#include <iostream>
#include <map>
#include <string>
using namespace std;

void countWords() {
    map<string, size_t> word_count;
    string word;
    while(cin >> word) {
        auto ret = word_count.insert({word, 1});
        if(!ret.second) {
            // ++((ret.first)->second)
            ++ret.first->second;
        }
    }
    for(auto &w : word_count) {
        cout << w.first << " occours " << w.second << ( (w.second>1)?  " times." : " time.") << endl;
    }
}

int main() {
    countWords();
    return 0;
}