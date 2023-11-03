#include <iostream>

using namespace std;

// 本质特定意义（使用场景下的浅拷贝），取名为移动构造，解决的还是效率问题
// 对象中含有堆上的资源 --> 深拷贝

// 抄近路

class HasPtrMem {
    public:
        // 默认构造
        HasPtrMem() : _d(new int(100)) {
            cout << "HasPtrMem() " << this << endl;
        }

        // 拷贝构造
        HasPtrMem(const HasPtrMem &another) : _d(new int(*another._d)) {
            cout << "HasPtrMem(const HasPtrMem &another) " << this << " -> " << &another << endl;
        }

        // 移动构造
        HasPtrMem(HasPtrMem &&another) {
            cout << "HasPtrMem(HasPtrMem &&another) " << this << " -> " << &another << endl;
            this->_d = another._d;
            another._d = nullptr;
        }

        ~HasPtrMem() {
            if (nullptr != _d) {
                delete _d;
            }
            cout << "~HasPtrMem() " << this << endl;
        }
        int *_d;
};

HasPtrMem getTemp() {
    return HasPtrMem();
}

int main() {

    // HasPtrMem a;
    // HasPtrMem b(a);

    // cout << a._d << endl;
    // cout << b._d << endl;

    HasPtrMem &&ret = getTemp();
    cout << "--------" << endl;
    cout << &ret << endl;
    cout << "--------" << endl;

    return 0;
}