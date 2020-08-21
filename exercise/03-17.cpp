#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

int main() {
    vector<string> wordlist;
    string word;
    while(cin >> word) {
        // Type Enter -> Ctrl+Z -> Enter after input all data to end loop.
        wordlist.push_back(word);
    }

    for(string &s : wordlist) {
        for(char &c : s) {
            c = toupper(c);
        }
    }

    for(string s : wordlist) {
        cout << s << endl;
    }

    return 0;
}