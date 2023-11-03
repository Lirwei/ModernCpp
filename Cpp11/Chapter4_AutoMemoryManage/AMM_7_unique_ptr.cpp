#include <iostream>
#include <memory>

using namespace std;

class A {
    public:
        A() {
            cout << "A() " << this << endl;
        }

        ~A() {
            cout << "~A() " << this << endl;
        }

        static void dis() {
            cout << "A::dis()" << endl;
        }
};

int main() {
    unique_ptr<int[]> up(new int[10]{1, 2, 3, 4, 5});
    for (int i = 0; i < 10; i++) {
        cout << (up[i] = 100) << endl;
    }

    unique_ptr<A[]> upA(new A[10]);
    for (int i = 0; i < 10; i++) {
        upA[i].dis();
    }

    return 0;
}