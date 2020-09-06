#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> up(new int(42));
    /* 
    * 无法引用 函数 "std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp> &) 
    * [其中 _Tp=int, _Dp=std::default_delete<int>]" 
    * (已声明 所在行数:394，所属文件:"D:\ProgramFiles\mingw\mingw64\lib\gcc\x86_64-w64-mingw32\8.1.0\include\c++\bits\unique_ptr.h") 
    * -- 它是已删除的函数
    */
    // 标准库为了禁止unique_ptr的拷贝和赋值，将拷贝构造函数和赋值函数声明为delete
    // unique_ptr(const unique_ptr) = delete
    // unique_ptr& operator = (const unique_ptr&) = delete

    unique_ptr<int> up2(up);
    return 0;
}