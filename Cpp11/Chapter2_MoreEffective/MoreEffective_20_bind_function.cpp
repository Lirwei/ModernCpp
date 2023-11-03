#include <iostream>
#include <functional>
using namespace std;

void foo()
{
    cout << "void foo()" << endl;
}

void func(int a)
{
    cout << "void func(int a)" << endl;
}

class Foo
{
public:
    void method()
    {
        cout << "Foo::void method()" << endl;
    }
    void method2(string s)
    {
        cout << "Foo:void method2()" << endl;
    }
};

class Bar
{
public:
    void method3(int a, string s)
    {
        cout << "Bar:void method3()" << endl;
    }
};

function<void(void)> f;

int main() {

    f = foo;
    f();
    f = bind(func, 100);
    f();

    Foo x;
    f = bind(&Foo::method, x);
    f();

    f = bind(&Foo::method2, x, "China");
    f();

    f = bind(&Bar::method3, Bar(), 10, "China");
    f();
    return 0;
}