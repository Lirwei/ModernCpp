#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Move {
    public:
        Move(int i) : _i(new int(i)) {
            cout << "Move(int i)" << endl;
        }

        Move(Move &&another) {
            cout << "Move(Move &&another)" << endl;
            _i = another._i;
            another._i = nullptr;
        }

        Move &operator=(Move &&another) {
            cout << "Move &operator=(Move &&another)" << endl;
            if (this != &another) {
                delete _i;
                _i = another._i;
                another._i = nullptr;
            }
            return *this;
        }

        ~Move() {
            if (_i != nullptr)
                delete _i;
            cout << "~Move()" << endl;
        }

        int *_i;
};

int main(int argc, char *argv[]) {
    vector<Move> vm;
    // vm.reserve(100);
    for (int i = 0; i < 100; i++)
        vm.push_back(Move(i)); //性能高的飞起
    return 0;
}