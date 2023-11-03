#include <iostream>
#include <functional>

using namespace std;

// std::bind 关联函数
int divide(int x, int y) {
    return x / y;
}

int main() {
    auto div1 = bind(divide, 10, 3);
    cout << div1() << endl;

    auto div2 = bind(divide, 10, placeholders::_1);
    cout << div2(3) << endl;

    auto div3 = bind(divide, placeholders::_1, placeholders::_2);
    cout << div3(10, 5) << endl;

    auto div4 = bind(divide, placeholders::_2, placeholders::_1);
    cout << div4(10, 5) << endl;

    return 0;
}