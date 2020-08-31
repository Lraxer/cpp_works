#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    multimap<string, string> author_book;
    author_book.insert({"a", "one"});
    author_book.insert({"b", "two"});
    author_book.insert({"b", "three"});
    author_book.insert({"c", "four"});
    author_book.insert({"c", "five"});
    author_book.insert({"d", "six"});
    author_book.insert({"d", "seven"});
    author_book.insert({"d", "eight"});

    string target1("d");
    string target2{"e"};

    /* find can only get the first element */

    // auto fc = author_book.find(target1);
    // if(fc!=author_book.end()) {
    //     auto fc2 = author_book.erase(fc);
    //     cout << fc2->second << endl;
    // } else {
    //     cout << "not found" << endl;
    // }

    auto pos = author_book.equal_range(target1);
    if(pos.first==pos.second) {
        cout << "not found" << endl;
    } else {
        author_book.erase(pos.first, pos.second);
    }

    for(auto &i : author_book) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}