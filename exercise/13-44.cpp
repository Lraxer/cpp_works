#include <iostream>
#include "13-44.hpp"

using namespace std;

int main() {
    // String(const char*)
    String s1("1234");
    // String(const char*)
    String s2 = "12434";
    // String()
    String s3;
    String s4("1");
    // String(const size_t, const char)
    String s5(5, '!');
    // String()
    String s6;

    // check size
    cout << s3.size() << endl;
    cout << s4.size() << endl;
    
    // String(const String&)
    s3 = s1;
    // operator=(const String&&)
    s4 = std::move(s5);

    // Overload << and >>
    cout << s4 << endl;
    cin >> s6;

    // Overload +
    s6 = s6+s1;

    // Overload <<
    cout << s6 << endl;

    // String(const String&&)
    String s7(std::move(s6));

    // Overload <<
    cout << s7 << endl;


    return 0;
}