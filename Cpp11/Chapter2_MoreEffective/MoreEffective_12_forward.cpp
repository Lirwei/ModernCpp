#include <iostream>

using namespace std;

template<typename T>
void PrintT(T &t) {
    cout << "lvaue" << endl;
}

template<typename T>
void PrintT(T &&t) {
    cout << "rvalue" << endl;
}

template<typename T>
void TestForward(T &&v) {
    PrintT(v);
    PrintT(std::forward<T>(v));
    PrintT(std::move(v));
}

int main() {
//    TestForward(1);
    int x = 1;
//    TestForward(x);
    TestForward(std::forward<int>(x));
    return 0;
}