#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main() {
    // note: "123" is const char*, there will be a warning if use list<char*>
    list<const char*> lcp{"123", "456", "789"};
    vector<string> vs;
    vs.assign(lcp.cbegin(), lcp.cend());

    for(const auto &str : vs) {
        cout << str << endl;
    }

    return 0;
}