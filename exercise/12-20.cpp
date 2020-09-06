#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "12-19.h"

using namespace std;

int main() {
    ifstream in("tmp.txt");
    if(!in) {
        cout << "can't open file" << endl;
        return -1;
    }
    StrBlob stb1;
    string tmpstr;
    while(getline(in, tmpstr)) {
        stb1.push_back(tmpstr);
    }

    for(auto it = stb1.begin();!isStrBlobPtrEqual(it, stb1.end());it.incr()) {
        cout << it.deref() << endl;
    }

    return 0;
}