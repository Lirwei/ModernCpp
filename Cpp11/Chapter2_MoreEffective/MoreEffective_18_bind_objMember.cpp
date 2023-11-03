#include <iostream>
#include <functional>

using namespace std;

struct Pair {
    int data;
    double source;
};

class MyPair {
    public:
        // void func()
        void func(int x, int y) {
            cout << "class MyPair void func()" << endl;
        }
};

int main() {
    Pair p = {100, 20};

    auto obj = bind(&Pair::data, p);
    cout << obj() << endl;

    // void (MyPair::*f)() = &MyPair::func;
    MyPair mp;
    auto objFunc = bind(&MyPair::func, mp, 10, 3);
    objFunc();

    return 0;
}