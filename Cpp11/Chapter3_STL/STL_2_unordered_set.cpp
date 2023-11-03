#include <iostream>
#include <unordered_set>

using namespace std;

void printUnorderSet(unordered_set<int> &m, char *pre) {
    unordered_set<int>::iterator it;
    cout << pre;
    for (it = m.begin(); it != m.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void test_unordered_set() {
    unordered_set<int> foo1;
    foo1.insert(1); // 普通插入
    foo1.insert(foo1.end(), 2); //

    unordered_set<int> foo2;
    foo2.insert(3);
    foo2.insert(4);
    foo2.insert(5);

    foo1.insert(foo2.begin(), foo2.end()); //  插入一个范围

    printUnorderSet(foo1, "After insert: ");

    // 查找
    unordered_set<int>::iterator it;
    it = foo1.find(4);
    if (it != foo1.end()) {
        cout << "find (4): " << *it << endl;

        // 删除
        foo1.erase(it);
        printUnorderSet(foo1, "After delete: ");
    }

    foo1.clear();
    cout << "size: " << foo1.size() << endl;


}
int main() {
    test_unordered_set();
    return 0;
}