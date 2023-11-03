#include <iostream>
#include <functional>

using namespace std;

int add(int x, int y) {
    cout << "int add(int x, int y)" << endl;
    return x + y;
}

double add(double x, double y) {
    cout << "double add(double x, double y)" << endl;
    return x + y;
}

class MyPair {
    public:
        // void func()
        int add(int x, int y) {
            cout << "class MyPair int add(int x, int y)" << endl;
            return x + y;
        }

        double add(double x, double y) {
            cout << "class MyPair double add(double x, double y)" << endl;
            return x + y;
        }
};

int main() {
//    auto func = bind((int (*)(int, int)) add, 10, 3);
    auto func = bind((double (*)(double, double)) add, 10, 3);
    func();

    MyPair mp;
    auto funcClass = bind((int (MyPair::*)(int, int)) &MyPair::add, mp, 10, 3);
//    auto funcClass = bind((double (MyPair::*)(double, double)) &MyPair::add, mp, 10, 3);
    funcClass();
    return 0;
}