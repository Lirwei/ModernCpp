#include <iostream>

using namespace std;

typedef void (*PF)();

void func() {
    cout << "hello, world!" << endl;
}

int main() {
    int i = 10;
    decltype(i) di;
    cout << sizeof(i) << "   " << sizeof(di) << endl;

    decltype("China") p = "aaaaa";
    cout << sizeof(p) << endl;

    decltype(string("China")) a;
    cout << sizeof(a) << endl;

    char * pp = "China";
    decltype(pp) dp;
    cout << sizeof(dp) << endl;

    PF pf = func;
    decltype(pf) f = func;
    f();

    return 0;
}