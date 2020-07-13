#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void readFile2Vector(const string& fileName, vector<string>& strvec ) {
    ifstream ifs(fileName);
    if(ifs) {
        string tmp;
        while(getline(ifs, tmp)) {
            strvec.push_back(tmp);
        }
        ifs.close();
    }
    for(const string& sline: strvec) {
        istringstream istr(sline);
        string tmp;
        while(istr>>tmp) {
            cout << tmp << endl;
        }
    }
}