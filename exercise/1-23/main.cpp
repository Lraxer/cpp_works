#include <iostream>
#include "Sales_item.h"
//我认为这样是有问题的，因为ISBN不是集中展示，而是即时的。
//原答案
int main() {
    Sales_item trans1, trans2;

    int num = 1;

    std::cout << "请输入若干条销售记录" << std::endl;

    if(std::cin >> trans1) {
        while (std::cin >> trans2) {
            if (compareIsbn(trans1, trans2)) {
                num++;
            }
            else {
                std::cout << trans1.isbn() << "共有"
                << num << "条销售记录" << std::endl;

                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << "共有"
        << num << "条销售记录" << std::endl;
    }
    else {
        std::cout << "无数据" << std::endl;
        return -1;
    }
    return 0;
}
