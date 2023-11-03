#include <iostream>
using namespace std;
class A {
    public:
        A() {
            cout << "A()" << this << endl;
        }

        ~A() {
            cout << "~A()" << this << endl;
        }

        A(const A &another) {
            cout << "A(const A&) " << &another << " -> " << this << endl;
        }

        void dis() {
            cout << "xxxxoooooooooooo" << endl;
        }

        void dis() const {
            cout << "xxxxoooooooooooo" << endl;
        }
};

A getObjectA() // 拷贝不可避免，临时对象一定会产生
{
    return A();
}

int main(int argc, char *argv[]) {
//    A a = getObjectA();
    A &&a = getObjectA(); // 引用的是临时对象，扩展了临时对象的作用域，延长了其生命周期

    a.dis();
    return 0;
}