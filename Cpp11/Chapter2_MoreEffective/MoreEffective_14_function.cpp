#include <iostream>
#include <map>

using namespace std;

// std::function 统一接口：可以包装函数、函数指针、lambda、仿函数

int add(int x, int y) {
    return x + y;
}

int minux(int x, int y) {
    return x - y;
}

typedef int (*MINUS)(int, int);

class Divide {
    public:
        int operator()(int x, int y) {
            return x / y;
        }
};

int main() {
    auto op = std::function<int(int, int)>(add);
    cout << op(1, 2) << endl;

    MINUS mop = minux;
    op = std::function<int(int, int)>(mop);
    cout << op(1, 2) << endl;

    auto mul = [](int x, int y) -> int { return x * y; };
    op = function<int(int, int)>(mul);
    cout << op(3, 4) << endl;

    Divide div;
    op = function<int(int, int)>(div);
    cout << op(6, 2) << endl;

    map<string, std::function<int(int, int)>> mp = {
        {"+", add},
        {"-", mop},
        {"*", mul},
        {"/", div}};
    cout << endl;
    cout << mp["+"](10, 2) << endl;
    cout << mp["-"](10, 2) << endl;
    cout << mp["*"](10, 2) << endl;
    cout << mp["/"](10, 2) << endl;
    return 0;
}