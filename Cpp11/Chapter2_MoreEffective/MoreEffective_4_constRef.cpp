#include <iostream>

using namespace std;

// const T &  -> &&

class A {
    public:
        A() {
            cout << "A() " << this << endl;
        }

        ~A() {
            cout << "~A() " << this << endl;
        }

        A(const A &another) {
            cout << "A(const A&) " << this << " copy from " << &another << endl;
        }

        void dis() {
            cout << "xxxxoooooooooooo" << endl;
        }

        void dis() const {
            cout << "xxxxoooooooooooo" << endl;
        }
};

//void func(A a) {
//
//}

//void func(const A &a) { // const 不可去掉
//
//}

void func(A &&a) {

}

A getObjectA() // 拷贝不可避免，临时对象一定会产生
{
    return A();
}

int main(int argc, char *argv[]) {
    func(A());


//    const A &a = getObjectA(); // 此时a必须调用const成员函数
//    a.dis();

    A &&a = getObjectA();
    a.dis();

    return 0;
}