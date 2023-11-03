#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

void printEven(int i) {
    if (i % 2 == 0)
        cout << i << "    is    even" << endl;
    else
        throw logic_error("not    even");
}

void printThreadId(int id) {
    try {

        lock_guard<mutex> lck(mtx);//栈自旋，抛出异常时栈对象自我析构。
        printEven(id);

    }
    catch (logic_error &) {
        cout << "exception caught" << endl;
    }
}

int main() {
    thread ths[10]; // spawn 10 threads
    for (int i = 0; i < 10; i++) {
        ths[i] = thread(printThreadId, i + 1);
    }
    for (auto &th: ths)
        th.join();
    return 0;
}