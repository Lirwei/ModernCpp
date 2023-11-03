#include <iostream>
#include <thread>

using namespace std;

volatile int counter(0);
mutex mtx;

void increase10ktimes() {
    for (int i = 0; i < 10000; i++) {
//        mtx.lock();
        while (!mtx.try_lock()) {
            cout << this_thread::get_id() << " wait.\n";
        }
        counter++;
        mtx.unlock();
    }
}

int main() {

    thread ths[10];
    for (int i = 0; i < 10; i++) {
        ths[i] = thread(increase10ktimes);
    }

    for (auto &th: ths) {
        th.join();
    }

    cout << counter << endl;

    return 0;
}