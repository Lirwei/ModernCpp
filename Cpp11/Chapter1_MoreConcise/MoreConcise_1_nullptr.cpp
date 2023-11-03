#include <iostream>

using namespace std;
// nullptr 是用于解决NULL和0的有疑义关系的。NULL通常被义为(void*)0。在如下应用中会引发歧义。

void f(int) {
    cout << "f(int)" << endl;
}

void f(bool) {
    cout << "f(bool)" << endl;
}

void f(void *) {
    cout << "void f(void *)" << endl;
}

int main() {
    f(0); // calls f(int), not f(void*)
    // f(NULL); // might not compile, but typically calls f(int). Never calls f(void*)
    f(nullptr); // calls f(void*) overload
}