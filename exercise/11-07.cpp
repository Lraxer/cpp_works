#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void familyInfo() {
    map<string, vector<string>> famMap{
        {"Jack", {"Jackie", "Julia"}},
        {"Lotte", {"Lorian", "Lothric"}}, 
        {"Gereon", {"Gary", "Gery", "Gallup"}}
    };
    string child{"Rath"};
    famMap["Gereon"].push_back(child);
    for(auto &s : famMap["Gereon"]) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    familyInfo();
    return 0;
}