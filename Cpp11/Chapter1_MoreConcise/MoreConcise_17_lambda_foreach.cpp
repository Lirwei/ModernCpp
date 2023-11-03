#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vi = {1, 2, 3, 4, 5};
    for_each(vi.begin(), vi.end(), [](int &i) {
        cout << i << endl;
    });
    return 0;
}