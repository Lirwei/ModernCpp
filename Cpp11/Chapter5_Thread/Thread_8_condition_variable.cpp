#include <iostream>
#include <thread>

using namespace std;

bool ready = false;
mutex mtx;
condition_variable cv;

void printId(int id) {
    unique_lock<mutex> lck(mtx);
    while (!ready) {
        cv.wait(lck);
    }
    cout << "id = " << id << endl;
}

void go() {
    lock_guard<mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}

int main() {
    thread ths[10];

    for (int i = 0; i < 10; i++) {
        ths[i] = thread(printId, i);
    }

    this_thread::sleep_for(chrono::seconds(5));
    go();

    for (auto &th: ths) {
        th.join();
    }

}