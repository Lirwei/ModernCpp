#include <iostream>

using namespace std;

int main() {

    // ap1,ap2 拥有同一个对象，在析构时都试图删除p指针，这是不被允许的。
    int *p = new int(10);
    {
        auto_ptr<int> ap1(p);
        cout << *ap1 << endl;
    }
    auto_ptr<int> ap2(p);
    cout << *ap2 << endl;
    return 0;
}