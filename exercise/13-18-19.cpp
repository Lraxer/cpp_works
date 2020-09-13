#include <iostream>
#include <string>

using namespace std;

class Employee{
friend void printout(const Employee&);
public:
    Employee(): name(string()), num(autonum++) {}
    Employee(const string &newem): name(newem), num(autonum++) {}
    Employee(const Employee &em): name(em.name), num(autonum++) {}
    Employee& operator= (const Employee &em) {
        // do not need to increase autonum
        name = em.name;
        return *this;
    }
private:
    string name;
    int num;
    static int autonum;
};

void printout(const Employee &em) {
    cout << em.name << " " << em.num << endl;
}

int Employee::autonum = 1;


int main() {
    Employee a("Tony"), b=a, c;
    c = b;
    printout(a); printout(b); printout(c);
    return 0;
}