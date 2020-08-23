#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
using std::placeholders::_1;

bool countCondition(const string &str, const vector<string>::size_type &sz) {
    return str.size()>=sz;
}

void longerThan6(const vector<string> &words, const vector<string>::size_type &sz) {
    int countnum = count_if(words.begin(), words.end(), bind(countCondition, _1, sz));
    cout << "The number of string length which is 6 or longer is " << countnum << " ." << endl;
}

int main() {
    vector<string> words{"the", "quicker", "red", "fox", "jumps", "over", "the", "slower", "red", "turtle"};
    longerThan6(words, 6);
    return 0;
}