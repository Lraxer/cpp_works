#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <string>
using namespace std;

void countWords() {
    map<string, size_t> word_count;
    set<char> exclude{'.', ',', '?', ';', ':', '!'};
    string word;
    while(cin>>word) {
        word[0] = tolower(word[0]);
        if(exclude.find(*(word.end()-1))==exclude.end()) {
            ++word_count[word];
        } else {
            word.erase(word.end()-1);
            ++word_count[word];
        }
    }
    for(const auto &w : word_count) {
        cout << w.first << " occours " << w.second << ( (w.second>1)?  " times." : " time.") << endl;
    }
}

int main() {
    countWords();
    return 0;
}