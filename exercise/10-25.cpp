#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;
using namespace std::placeholders;

string make_plural(int count, const string &word, const string &suffix) {
    return count>1 ? word+suffix : word;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz) {
    return s.size() < sz;
}

void biggies(vector<string> &words, const vector<string>::size_type &sz) {
    elimDups(words);
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [] (const string &str) { cout << str << " ";});
    cout << endl;
}

int main() {
    vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 4);
    return 0;
}