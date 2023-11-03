#include <iostream>

using namespace std;

// 如果没有显式地为一个类定义某个特殊成员函数，
// 而又需要用到该特殊成员函数时，
// 则编译器会隐式的为这个类生成一个默认的特殊成员函数

class A {
    public:
        A() = default;
        ~A() = default;
        A(const A &another) = default;
        A &operator=(const A &another) = default;
};

int main() {
    A a;
    return 0;
}