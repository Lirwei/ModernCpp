#include <iostream>
#include <memory>

using namespace std;

class Copy {
    public:
        Copy(int i = 0) : _i(new int(i)) {
            cout << "Copy(int i) " << this << endl;
        }
        Copy(const Copy &another)
            : _i(new int(*another._i)) {
            cout << "Copy(const Copy &another)" << endl;
        }
        ~Copy() {
            cout << "~Copy() " << this << endl;
        }
        void dis() {
            cout << "*_i = " << *_i << endl;
        }
        int *_i;
};

void testGet() {
    unique_ptr<Copy> up(new Copy(78));
    Copy *pc = up.get(); // 获取所托管资源指针
    cout << "=====" << endl;
    cout << *pc->_i << endl;
    cout << *up->_i << endl;
}

void testIfEmpty() {
//    unique_ptr<Copy> up(new Copy);
    unique_ptr<Copy> up;
    if (up) // 非空为真
        cout << "not empty" << endl;
    else
        cout << "empty" << endl;
}

void testRelease() {
//    unique_ptr<Copy> up;
    unique_ptr<Copy> up(new Copy(78));
    Copy *pc = up.release();
    if (pc != nullptr) {
        cout << "==============" << endl;
        cout << *pc->_i << endl;
//        cout << *up->_i << endl; // 托管不可用
        delete pc; // 放弃托管，返回资源指针，需要手动释放
    }
}

void testRest() {
    {
        unique_ptr<Copy> up(new Copy(78));
//        up.reset(); // reset 如果参数空，直接释放，非空托管新
        up.reset(new Copy(199)); // 非空，托管新资源，释放旧资源
        cout << "======" << endl;
    }
    cout << "++++++" << endl;
}

void testMove() {
    unique_ptr<Copy> up1(new Copy(78));
    unique_ptr<Copy> up2(std::move(up1));
    up2->dis();
//    up1->dis(); // up1托管的资源被移动到up2
}

int main() {
//    testGet();
//    testIfEmpty();
//    testRelease();
//    testRest();
    testMove();
    return 0;
}