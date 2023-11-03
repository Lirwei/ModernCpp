#include <iostream>

using namespace std;

// auto 能够实现类型的自我推导，并不代表一个实际的类型声明。
// auto 只是一个类型声明的占位符。
// auto声明的变量，必须马上初始化，以让编译器推断出它的实际类型，并在编译时将auto占位符替换为真正的类型。

typedef void (*PF)();

void func() {
    cout << "void func()" << endl;
}

//void foo(auto v) { // error
void foo() {
    cout << "void foo()" << endl;
}

int main() {
    auto p = "China";
    auto s = string("China");
    cout << sizeof(char *) << "   " << sizeof(string) << endl;
    cout << sizeof(p) << "   " << sizeof(s) << endl;

    cout << "============" << endl;
    int arr[] = {1, 2, 4};
    auto pArr = arr;
    auto pf = func;

    cout << sizeof(p) << " " << typeid(p).name() << endl;
    cout << sizeof(pArr) << " " << typeid(pArr).name() << endl;
    cout << sizeof(pf) << " " << typeid(pf).name() << endl;

    return 0;
}

int main1() {
    auto i = 5;
    cout << sizeof(i) << endl;

    auto d = 5.5;
    cout << sizeof(d) << endl;

    auto x = i + d;
    cout << sizeof(x) << endl;

    const auto n = 10;

    auto pf = func;
    pf();

    return 0;
}