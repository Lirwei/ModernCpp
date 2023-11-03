#include<iostream>

using namespace std;

template<typename T>
class my_auto_ptr {
    public:
        explicit my_auto_ptr(T *t) : _t(t) {}

        T *operator->() const {
            return _t;
        }

        T &operator*() const {
            return *_t;
        }

        ~my_auto_ptr() {
            delete _t;
        }
    private:
        T *_t;
};

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
    my_auto_ptr<A> a(new A); //资源获取，初始化
    a->dis();
    (*a).dis();
}

int main() {
    func();
    return 0;
}