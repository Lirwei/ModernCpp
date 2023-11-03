#include <iostream>
#include <thread>

using namespace std;

// detach

void func(int n, string s) {
    for (int i = 0; i < n; i++) {
        cout << s << endl;
    }
}

int main()
{
    int n = 5;
    string str = "China";

    thread t(func, n, str);

    t.detach();
    if (!t.joinable()) { // detach后的线程，不能再join，是否可以join可以通过joinable来判断
        this_thread::sleep_for(chrono::seconds(5));
        cout << "main thread is waiting over!";
    } else {
        t.join();
    }

    return 0;
}