#include <iostream>
#include <map>
#include <string>
using namespace std;

void countWords() {
    map<string, size_t> word_count;
    string word;
    while(cin>>word) {
        ++word_count[word];
    }
    for(const auto &w : word_count) {
        cout << w.first << " occours " << w.second << ( (w.second>1)?  " times." : " time.") << endl;
    }
}

int main() {
    countWords();
    return 0;
}