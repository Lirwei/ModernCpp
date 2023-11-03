#include <iostream>
#include <list>
#include <functional>

using namespace std;

class FunctorA {
    public:
        void operator()() {
            cout << "class FunctorA" << endl;
        }
};

class FunctorB {
    public:
        void operator()() {
            cout << "class FunctorB" << endl;
        }
};

class Object {
    public:
        Object(FunctorA a, FunctorB b) {
            _list.push_back(a);
            _list.push_back(b);
        }

        void notify() {
            for (auto &item: _list) {
                item();
            }
        }

    private:
        list<std::function<void()>> _list;
};

int main() {
    FunctorA a;
    FunctorB b;
    Object obj(a, b);
    obj.notify();
    return 0;
}