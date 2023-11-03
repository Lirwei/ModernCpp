#include <iostream>
#include <thread>

using namespace std;

/**
 * 线程拥有自己独立的栈，可以共享全局的变量，在线程启动的时候可以传入启动参数
 * 除了传入参数，共享全局以外，还可以传入本地变量的引用。
 * @param n
 * @param s
 */

void func(int &n, string &s) {
    for (int i = 0; i < n; i++) {
        cout << s << endl;
    }

    n = 100;
    s = "China n";
}

int main() {
    int n = 5;
    string str = "China";

    thread t(func, std::ref(n), std::ref(str));
//    thread t(func, n, str); // 编译不通过
    t.join();
    cout << n << " " << str << endl;

    return 0;
}