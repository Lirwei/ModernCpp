#include <iostream>

using namespace std;

#if 0
int main() {

    double a = 3.14;
    const int &ra = a;

    cout << "a = " << a << endl;
    cout << "ra = " << ra << endl;

    a = 4.14;

    cout << "a = " << a << endl;
    cout << "ra = " << ra << endl;
    return 0;

}
#endif

#if 1
long long func() {
    return 10;
}

int main() {
    // int a = 100;
    // const int a;
    // int const a;

    // int *p;
    // const int *p;
    // int const *p;

    // int * const p;
    // const int * const p;

    // 类成员 初始化 函数(重载)	 对象 对于指针或者引用  const_cast脱

    int a = 100;
    const int &ra = 10; // 产生了临时变量
    const double &rd = a;

    int &&aa = 10;
    double &&dd = a;
    cout << "a = " << a << endl;
    cout << "dd = " << dd << endl;

    a = 2;
    cout << "a = " << a << endl;
    cout << "dd = " << dd << endl;

    // long long &rll = func(); // err
    const long long &rll = func();
    long long &&dll = func();

    return 0;
}
#endif