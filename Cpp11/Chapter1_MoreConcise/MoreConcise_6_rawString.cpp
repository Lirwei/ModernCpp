#include <iostream>

using namespace std;

#define path "Users\Lrwei\Desktop\C++11"
#define path1 "Users\\Lrwei\\Desktop\\C++11"
#define path2 R"(Users\Lrwei\Desktop\C++11)"

int main() {
    cout << path << endl;
    cout << path1 << endl;
    cout << path2 << endl;
    return 0;
}