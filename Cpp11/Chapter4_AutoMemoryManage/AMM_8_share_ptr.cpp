#include <iostream>

using namespace std;

// 共享原因是：引用计数，每次被引用，引用计数会加1，引用的对象小时，引用的对象消失，引用计数减1
// 基本数据类型计数测试
int main() {
    int *p = new int(100);

    shared_ptr<int> sp(p);
    cout << *sp << endl;
    cout << "count1: " << sp.use_count() << endl;
    {
        shared_ptr<int> sp2(sp);
        cout << *sp2 << endl;
        cout << "count2: " << sp.use_count() << endl;
    }
    cout << "count3: " << sp.use_count() << endl;
    shared_ptr<int> sp3(sp);
    cout << *sp3 << endl;
    cout << "count4: " << sp3.use_count() << endl;
    return 0;
}

#if 0
int main() {
    int *p = new int(100);
    {
        shared_ptr<int> sp(p);
        cout << *sp << endl;
    }
    shared_ptr<int> sp2(p); // err
    return 0;
}
#endif

#if 0
int main() {
    shared_ptr<int> sp(new int(10));
    cout << *sp << endl;
    cout << "count: " << sp.use_count() << endl;

    shared_ptr<int> sp2(sp);
    cout << "count: " << sp.use_count() << endl;
    cout << "count: " << sp2.use_count() << endl;
    return 0;
}
#endif