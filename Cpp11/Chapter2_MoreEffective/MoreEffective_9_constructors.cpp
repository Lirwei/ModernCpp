#include <iostream>

using namespace std;

// 六大构造

class A {
    public:
        explicit A(int *i = nullptr) : _i(!i ? new int(0) : new int(*i)) {
            cout << "A(int * i = nullptr)" << endl;
            cout << *_i << endl;
        }

        // 拷贝构造
        A(const A &another) {
            _i = new int;
            *_i = *another._i;
            cout << "A(const A &another)" << endl;
        }

        // 赋值构造
        A &operator=(const A &another) {
            cout << "A &operator=(const A &another)" << endl;
            if (this != &another) {
                delete _i;
                _i = new int;
                *_i = *another._i;
            }
            return *this;
        }

        // 移动构造
        A(A &&another) {
            _i = another._i;
            another._i = nullptr;
            cout << "A(A &&another)" << endl;
        }

        A &operator=(A &&another) {
            cout << "A &operator=(A &&another)" << endl;
            if (this != &another) {
                delete _i;
                _i = another._i;
                another._i = nullptr;
            }
            return *this;
        }

        ~A() {
            if (_i != nullptr) {
                delete _i;
            }
            cout << "~A()" << endl;
        }
        int *_i;
};

int main() {

    A a;
    // A b(a);
    // A c(std::move(a));

    A d(new int(100));
    // d = a;
    d = std::move(a);

    return 0;
}