#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    map<string, vector<int>> vecmap{{"a", {1,2}}, {"b", {3,4}}, {"c", {5,6}}};
    auto c = vecmap.find("c");
    if(c!=vecmap.end()) {
        cout << c->first << " ";
        for(const auto &i : c->second) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}