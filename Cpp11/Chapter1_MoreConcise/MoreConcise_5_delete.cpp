#include <iostream>

using namespace std;

// 显式禁用某个函数，在函数声明后上加“=delete;”

class Singleton {
    public:
        static Singleton *getInstance() {
            if (nullptr == _ins) {
                _ins = new Singleton;
            }
            return _ins;
        }

        // static void releaseInstance() {
        //     if (nullptr != _ins)
        //         delete _ins;
        //     _ins = nullptr;
        // }

        ~Singleton() = delete;
        Singleton(const Singleton &another) = delete;

    private:
        Singleton() = default;
        static Singleton *_ins;
};

Singleton *Singleton::_ins = nullptr;

int main() {
    Singleton *p = Singleton::getInstance();
    // delete p; // error
    return 0;
}