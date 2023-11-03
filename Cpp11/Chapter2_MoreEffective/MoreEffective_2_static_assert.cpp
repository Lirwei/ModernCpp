#include <iostream>

using namespace std;

// static_assert(sizeof(void *) != 4, "64-bit code generation is not supported.");

template<typename T, typename U>
int my_bit_copy(T &t, U &u) {
    static_assert(sizeof(t) == sizeof(u), "parameters must have same with");
}

int main() {
    int a;
    float b;
    my_bit_copy(a, b);

    // char c;
    // my_bit_copy(a, c);
    return 0;
}