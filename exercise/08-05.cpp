#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void readFile(const string& fileName, vector<string>& strline) {
    ifstream ifs(fileName);
    if(ifs) {
        string tmp;
        while(ifs>>tmp) {
            strline.push_back(tmp);
        }
        ifs.close();
    }
}