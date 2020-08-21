#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    string tmp, max_rep_str;
    int Repeat_Cnt=0, max_rep_cnt=0;

    cin >> str;
    tmp = str;
    max_rep_str = str;
    // ++Repeat_Cnt;
    // max_rep_cnt = Repeat_Cnt;
    while (cin >> str)
    {
        if(str==tmp) {
            ++Repeat_Cnt;
        } else {
            if(Repeat_Cnt>max_rep_cnt) {
                max_rep_cnt = Repeat_Cnt;
                max_rep_str = tmp;
            }
            Repeat_Cnt = 0;
            tmp = str;
        }
    }
    if(max_rep_cnt) {
        cout << "word: " << max_rep_str << endl;
        cout << "count: " << max_rep_cnt+1 << endl;
    } else {
        cout << "No words appear consecutively." << endl;
    }
    
    return 0;
}