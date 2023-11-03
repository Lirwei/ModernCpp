#include <iostream>

using namespace std;

// 闭包
// & 引用
// = 复制产生复本 const mutable

int main() {
    int x = 100, y = 200;
    auto f = [&x,y]() mutable {
        x = 50;
        y = 50;
        cout << x << " : " << y << endl;
    };
    f();
    cout << x << " : " << y << endl;
    return 0;
}

int main2() {
    int x = 100, y = 200;
    auto f = [=]() mutable {
        x = 50;
        y = 50;
        cout << x << " : " << y << endl;
    };
    f();
    cout << x << " : " << y << endl;
    return 0;
}

int main1() {
    int x = 100, y = 200;
    auto f = [&]() {
        x = 50;
        y = 50;
        cout << x << " : " << y << endl;
    };
    f();
    cout << x << " : " << y << endl;
    return 0;
}

/*
 []         不截取任何变量。
 [bar]      仅对外部变量 bar 值传递在函数体中使用。
 [&bar]     仅对外部变量 bar 引用传递在函数体中使用。
 [x, &y]    仅 x 按值传递，y 按引用传递在函数体中使用。
 [&]        截取外部作用域中所有变量，并作为引用传递在函数体中使用。
 [=]        截取外部作用域中所有变量，并按值传递在函数体中使用。
 [=, &foo]  截取外部作用域中所有变量，并值传递在函数体中使用，但是对 foo 变量使用引用传递。
 [&, =foo]  截取外部作用域中所有变量，在函数体中作引用传递使用，但是对 foo 变量作值传递。=foo -> foo
 */