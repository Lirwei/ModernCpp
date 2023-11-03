#include <iostream>
using namespace std;

class A {
    public:
        A() {
            cout << "A()" << endl;
        }

        ~A() {
            cout << "~A()" << endl;
        }

        void dis() {
            cout << "dis()" << endl;
        }
};

void func() {
    auto_ptr<A> a(new A); //资源获取，初始化
    a->dis();
    (*a).dis();
}

int main() {
    func();
    return 0;
}