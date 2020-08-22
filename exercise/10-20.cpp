#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void longerThan6(const vector<string> &words, const vector<string>::size_type &sz) {
    int countnum = count_if(words.begin(), words.end(), [sz] (const string &str) { return str.size()>=sz; });
    cout << "The number of string length which is 6 or longer is " << countnum << " ." << endl;
}

int main() {
    vector<string> words{"the", "quicker", "red", "fox", "jumps", "over", "the", "slower", "red", "turtle"};
    longerThan6(words, 6);
    return 0;
}