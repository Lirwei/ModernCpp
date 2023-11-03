#include <iostream>
#include <memory>

using namespace std;

// 做参数传递时，也会出现两个指针对同一段资源产生了引用行为
class Copy {
    public:
        explicit Copy(int i) : _i(new int(i)) {
            cout << "Copy(int i)" << endl;
        }

        Copy(const Copy &another)
            : _i(new int(*another._i)) {
            cout << "Copy(const Copy &another)" << endl;
        }

        ~Copy() {
            cout << "~Copy()" << endl;
        }

        int *_i;
};

void func(auto_ptr<Copy> apc) {
    cout << "func" << endl;
}

int main(int argc, char *argv[]) {
    auto_ptr<Copy> apc(new Copy(10));
    cout << *apc->_i << endl;
    func(apc);
    cout << "==========" << endl;
    cout << *apc->_i << endl; // new Copy(10)已经在func调用后释放了
    return 0;
}