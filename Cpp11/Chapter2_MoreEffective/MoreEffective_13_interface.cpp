#include <iostream>

using namespace std;

class Oper {
    public:
        virtual int op(int x, int y) = 0;
};

class Add : public Oper {
    public:
        virtual int op(int x, int y) {
            return x + y;
        }
};

class Minus : public Oper {
    public:
        virtual int op(int x, int y) {
            return x - y;
        }
};

int main() {
    Add add;
    cout << add.op(4, 5) << endl;
    Minus minus;
    cout << minus.op(4, 5) << endl;
    return 0;
}