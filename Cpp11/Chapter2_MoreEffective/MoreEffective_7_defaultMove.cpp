#include <iostream>
#include <memory>

using namespace std;

class Copy {
    public:
        Copy(int i = 0) : _i(new int(i)) {
            cout << "Copy(int i)" << endl;
        }

        Copy(const Copy &another) : _i(new int(*another._i)) {
            cout << "Copy(const Copy &another)" << endl;
        }

        Copy &operator=(const Copy &another) {
            cout << "Copy &operator=(Copy &another)" << endl;
            if (this == &another)
                return *this;
            delete _i;
            _i = new int(*another._i);
            return *this;
        }

        ~Copy() {
            delete _i;
            cout << "~Copy()" << endl;
        }

        int *_i;
};

class Move {
    public:
        Move(int i = 0) : _i(new int(i)) {
            cout << "Move(int i)" << endl;
        }

        Move(const Move &another) : _i(new int(*another._i)) {
            cout << "Move(const Copy &another)" << endl;
        }

        Move(Move &&another) {
            cout << "Move(Move &&another)" << endl;
            _i = another._i;
            another._i = nullptr;
        }

        Move &operator=(const Move &another) {
            cout << "Move &operator=(Copy &another)" << endl;
            if (this == &another)
                return *this;
            delete _i;
            _i = new int(*another._i);
            return *this;
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

Copy getCopy() {
    return Copy(1);
}

Move getMove() {
    return Move(1);
}
#if 1
int main() {
//    Move m;
//    Move n(m);

    Copy m;
    Copy n(std::move(m));

    return 0;
}
#endif

#if 0
int main() {

//    Copy rrc = getCopy();
    Copy &&rrc = getCopy();

//    Move rrm = getMove();
    Move &&rrm = getMove();
    return 0;
}
#endif