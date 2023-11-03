#include <iostream>
#include <memory>

using namespace std;

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
        void dis() const {
            cout << "*_i = " << *_i << endl;
        }
        int *_i;
};

void func(unique_ptr<Copy> apc) {
}

int main(int argc, char *argv[]) {

//    unique_ptr<Copy> up(new Copy(99));
//    up->dis();
//    unique_ptr<Copy> up2(up); // err
//    func(up); // err

    // 仍然有二次释放的问题
    int *p = new int(10);
    {
        unique_ptr<int> upi(p);
        cout << *upi << endl;
    }

    unique_ptr<int> upi2(p);
    cout << *upi2 << endl;

    return 0;
}