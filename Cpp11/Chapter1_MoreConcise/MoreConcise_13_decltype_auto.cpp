#include <iostream>
using namespace std;

template<class T1, class T2, class T3>
T1 sum1(T2 a, T3 b) {
    return a + b;
}

// 尾推导
template<class T2, class T3>
auto sum2(T2 a, T3 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    int i = 100;
    double d = 100.1;

    auto s1 = sum1<decltype(i + d), int, double>(i, d);

    auto s2 = sum2(i, d);
    cout << s2 << endl;
    return 0;
}