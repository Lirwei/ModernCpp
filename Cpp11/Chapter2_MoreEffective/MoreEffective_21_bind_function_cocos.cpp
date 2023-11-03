#include <iostream>
#include <functional>

using namespace std;

#define CC_CALLBACK_0(__selector__, __target__, ...) std::bind(&__selector__, __target__, ##__VA_ARGS__)
#define CC_CALLBACK_1(__selector__, __target__, ...) std::bind(&__selector__, __target__, std::placeholders::_1, ##__VA_ARGS__)

class A {
    public:
        void func() {
            cout << "A::func()" << endl;
        }

        void foo(int a) {
            cout << "A::foo(int a)" << endl;
        }
};

int main() {
    A a;
    std::function<void(void)> pf = CC_CALLBACK_0(A::func, &a);
    pf();

    std::function<void(int)> pfa = CC_CALLBACK_1(A::foo, &a);
    pfa(100);
    return 0;
}