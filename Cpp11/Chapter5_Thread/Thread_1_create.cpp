#include <iostream>
#include <thread>

using namespace std;

void func() {
    cout << "func thread: " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(5));
}

int main() {
    cout << "main thread: " << this_thread::get_id() << endl;
    thread t(func);
    t.join(); // 主线程main与子线程t之间处于同步关系
    cout << "thread is over" << endl;
    return 0;
}