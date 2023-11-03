#include <iostream>
#include <fstream>

using namespace std;

enum class Season : char {
    Spring, Summer, Autumn, Winter
};

enum struct Xx : long long {
    Spring, Summer, Autumn, Winter
};

int main() {
    // Season s = Season::Winter;
    // Xx x = Xx::Autumn;
    cout << sizeof(Season::Spring) << endl;
    cout << (int) Season::Autumn << endl;

    return 0;
}

#if 0
class Season {
    public:
        enum _Season{
            Spring = 1, Summer, Autumn, Winter
        };
};

class XX {
    public:
        enum _XX{
            Spring = 1, Summer, Autumn, Winter
        };
};

class IOS {
    public:
        enum {
            in, out, trunc
        };
};

int main() {
    Season::_Season s = Season::Summer;
    cout << s << endl;


    fstream fs("a.txt", ios::in);

    return 0;
}
#endif