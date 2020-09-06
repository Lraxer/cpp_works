#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};

connection connect(destination* pd) {
    cout << "Open connection" << endl;
    return connection();
}

void disconnect(connection c) {
    cout << "Close connection" << endl;
}

void end_connection(connection *p) {
    disconnect(*p);
}

void f(destination &d) {
    connection c = connect(&d);
    // use end_connection
    shared_ptr<connection> p(&c, end_connection);
    // use lambda
    shared_ptr<connection> q(&c, [] (connection *p) {disconnect(*p);});
}

int main() {
    destination d;
    f(d);
    return 0;
}