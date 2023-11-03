#include <iostream>

using namespace std;

class G {
    public:
        virtual void func(int) = 0;
};

class H : public G {
    public:
//        void func(double) override { // 'func' marked 'override' but does not override any member functions
        void func(int) override {
        }
};

int main() {

}