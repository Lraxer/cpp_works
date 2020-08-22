#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string make_plural(int count, const string &word, const string &suffix) {
    return count>1 ? word+suffix : word;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, const vector<string>::size_type &sz) {
    elimDups(words);
    auto wc = partition(words.begin(), words.end(), [sz] (const string &str) { return str.size()>=sz;});
    // ex10-19 different output
    // auto wc = stable_partition(words.begin(), words.end(), [sz] (const string &str) { return str.size()>=sz;});
    auto count = wc-words.begin();
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), wc, [] (const string &str) { cout << str << " ";});
    cout << endl;
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
    return 0;
}