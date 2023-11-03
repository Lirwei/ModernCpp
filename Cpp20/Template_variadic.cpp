#include <iostream>

void print() {
    std::cout << "hello" << std::endl;
}

template<typename T, typename ...Types>
void print(const T &firstArgs, const Types &... args) {
    std::cout << firstArgs << std::endl;
    print(args...);
}

int main() {
//    print(7.5, 11, 42);
    int x = 1;
    int &r = x;
    std::cout << sizeof(r); // Object和其reference的大小相同，地址也相同
    return 0;
}