#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void findword(const string &newstr, string &result) {
    string exceptstr = "bdfhikltgjpqy";
    if((newstr.find_first_of(exceptstr))==string::npos) {
        result = result.size() > newstr.size() ? result : newstr;
    }
}

int main() {
    ifstream ifs("./9-49file.txt");
    if(!ifs) {
        return -1;
    }
    string newstr;
    string result;
    while(ifs>>newstr) {
        findword(newstr, result);
    }

    cout << result << endl;

    return 0;
}