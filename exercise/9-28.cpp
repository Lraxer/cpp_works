#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

void insertString(forward_list<string> &flst, const string &searstr, const string &inserstr) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while(curr!=flst.end()) {
        if(*curr==searstr) {
            curr = flst.insert_after(curr, inserstr);
            return ;
        } else {
            prev = curr;
            ++curr;
        }
    }
    flst.insert_after(prev, inserstr);
    return ;
}