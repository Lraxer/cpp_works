#include <iostream>

int main() {
    int x, y, i;

    std::cout << "������������\n";
    std::cin >> x >> y;

    if (x>=y) {
        for(i=y;i<=x;i++) {
            std::cout << i <<std::endl;
        }
    }

    else {
        for (i=x;i<=y;i++) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
