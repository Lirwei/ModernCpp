#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Arr {
    public:
        Arr() = default;
        Arr(const initializer_list<T> &il) {
            for (auto &i: il)
                vt.push_back(i);
        }
    protected:
        vector<T> vt;
};

int main() {
    Arr<int> arr;
    Arr<int> arr2 = {1, 2, 3};
    return 0;
}

#if 0
int sum(const initializer_list<int> &il) {
    int s = 0;
    for (auto i: il) {
        s += i;
    }
    return s;
}

int average(const initializer_list<int> &il) {
    int s = 0;
    for (auto i: il) {
        s += i;
    }
    return s/il.size();
}

int main() {
    int s = sum( {1, 2, 3, 4 } ); // 变参
    int av = average({1, 2, 3, 4});
    cout << "sum = " << s << " av = " << av << endl;
    return 0;
}
#endif