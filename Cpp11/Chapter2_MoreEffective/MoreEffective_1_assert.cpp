#include <iostream>

using namespace std;

char *myStrcpy(char *dest, const char *src) {
    assert(dest); // 运行时报错，主要用于调试使用
    char *p = dest;
    while ((*p++ = *src++));
    return p;
}

int main() {
    char *dest = nullptr, *src = nullptr;
    myStrcpy(dest, src);
    return 0;
}