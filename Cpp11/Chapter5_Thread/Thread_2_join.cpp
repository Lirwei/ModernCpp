#include <iostream>
#include <thread>

using namespace std;

void func() {
    this_thread::sleep_for(chrono::seconds(10));
}

void foo() {
    this_thread::sleep_for(chrono::seconds(5));
}

int main() {
    thread t1(func);
    thread t2(foo);

    t1.join();
    cout << "t1 is over" << endl;
    t2.join();
    cout << "t2 is over" << endl;

    return 0;
}