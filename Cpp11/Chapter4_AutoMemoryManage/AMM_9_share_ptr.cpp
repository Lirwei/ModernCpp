#include <iostream>
using namespace std;

class A {
    public:
        A() {
            cout << "A() " << this << endl;
        }

        ~A() {
            cout << "~A() " << this << endl;
        }

        void dis() {
            cout << "A::dis()" << endl;
        }
};

// 可以测试引用版本和非引用版本
void func(shared_ptr<A> sp) {
    if (sp.unique()) {
        cout << "unique" << endl;
    }
    cout << sp.use_count() << endl;
}

void foo(shared_ptr<A> &sp1) {
    cout << sp1.use_count() << endl;
}

void testRest() {
    {
        shared_ptr<A> sp(new A);
//        shared_ptr<A> sp1(sp);
        cout << sp.use_count() << endl;
        sp.reset(); // 计数减一，直至为0时不再减一
//        sp.reset();
//        sp.reset();
        cout << sp.use_count() << endl;
        cout << "+++++++" << endl;
    }
    cout << "======" << endl;
}

void testUnique() {
    shared_ptr<A> sp(new A);
    cout << sp.use_count() << endl;
    if (sp.unique()) { // 定义 bool unique() const _NOEXCEPT {return use_count() == 1;}
        cout << "unique" << endl;
    }
    func(sp);
    cout << sp.use_count() << endl;
}

void testReference()  {
    shared_ptr<A> sp1(new A);
    shared_ptr<A> sp2(sp1);
    shared_ptr<A> sp3(sp1);
    cout << sp1.use_count() << endl;
    foo(sp1);
    cout << sp1.use_count() << endl;
}

void testMove() {
    shared_ptr<A> sp1(new A);
    shared_ptr<A> sp2(sp1);
    shared_ptr<A> sp3(sp1);
    shared_ptr<A> spm = std::move(sp1); // 移动会将计数也一起移走
    cout << sp1.use_count() << endl; // 0
    cout << sp2.use_count() << endl; // 3
    cout << sp3.use_count() << endl; // 3
    cout << spm.use_count() << endl; // 3
}

int main() {
//    testRest();
//    testUnique();
//    testReference();
    testMove();
    return 0;
}