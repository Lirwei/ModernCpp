#include <iostream>
using namespace std;
class Complex {
    public:
        explicit Complex(float f = 0)
            : _f(new float(f)) {
            cout << "Complex()" << endl;
        }
        Complex(const Complex &another)
            : _f(new float(*another._f)) {
            cout << "Complex(const Complex &another)" << endl;
        }
        Complex(Complex &&another) noexcept: _f(another._f) {
            another._f = nullptr;
            cout << "Complex(Complex &&another)" << endl;
        }
        Complex &operator=(const Complex &another) {
            cout << "Complex &operator=(const Complex &another)" << endl;
            if (this != &another) {
                delete _f;
                _f = new float;
                *_f = *another._f;
            }
            return *this;
        }
        Complex &operator=(Complex &&another) noexcept {
            cout << "Complex &operator=(const Complex &&another)" << endl;
            if (this != &another) {
                delete _f;
                _f = another._f;
                another._f = nullptr;
            }
            return *this;
        }
        ~Complex() {
            if (nullptr != _f)
                delete _f;
        }
        float *_f;
};

class Moveable {
    public:
        Moveable(int i)
            : _i(new int(100)), _c(2.1) //先父类,再类对象,再本类
        {
            cout << "Moveable(int i)" << endl;
        }
        Moveable(const Moveable &another)
            : _i(new int(*another._i)), _c(another._c) {
            cout << "Moveable(const Moveable &another)" << endl;
        }
        Moveable(Moveable &&another) {
            cout << "Moveable(Moveable &&another)" << endl;
            _i = another._i;
            another._i = nullptr;
            _c = std::move(another._c); //走  Complex 移动赋值
        }
        ~Moveable() {
            if (_i != nullptr)
                delete _i;
        }
        int *_i;
        Complex _c; //类对象成员
};

int main(int argc, char *argv[]) {
    Moveable m(100);
    Moveable n(std::move(m)); //走移动构造
    return 0;
}