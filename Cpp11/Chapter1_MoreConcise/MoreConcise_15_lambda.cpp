#include <iostream>

using namespace std;

// [](){}
// []()->{}
int main() {
    auto f = [](int a = 10, int b = 20) { return a + b; };
    cout << f(1, 2) << endl;
    cout << [](int a, int b) { return a + b; }(5, 6) << endl;

    auto f2 = []() -> int { return 1 + 2; };
    cout << f2() << endl;
    return 0;
}

#if 0
// []{}
int main1() {
    auto f = [] {return 1 + 2;};
    cout << f() << endl;
    cout << [] {return 1 + 2;} () << endl;
    return 0;
}
#endif