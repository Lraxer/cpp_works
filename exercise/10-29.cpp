#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void readFile() {
    ifstream ifs("./test.txt");
    istream_iterator<string> initer(ifs), eof;
    vector<string> strvec;
    while(initer!=eof) {
        strvec.push_back(*initer++);
    }
    for(auto &i : strvec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    readFile();
    return 0;
}