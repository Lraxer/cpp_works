#include <iostream>

int main() {
    int a, b, tmp=0;
    std::cout << "Input two integers:" << std::endl;
    std::cin >> a >> b;
    if(a>b) {
        tmp = b;
        b = a;
        a = b;
    }
    tmp=a;
    while(tmp<=b) {
        std::cout << tmp << " ";
        tmp++;
    }
    std::cout << std::endl;

    return 0;
}