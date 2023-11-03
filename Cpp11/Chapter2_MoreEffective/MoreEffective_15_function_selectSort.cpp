#include <iostream>

using namespace std;

void selectSort(int *p, int n, std::function<int(int, int)> compare) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compare(p[i], p[j])) {
                p[i] ^= p[j];
                p[j] ^= p[i];
                p[i] ^= p[j];
            }
        }
    }
}

int main() {
    int arr[] = {1, 3, 5, 6, 9, 2, 4, 6, 8, 10};
    for_each(arr, arr + 10, [](int &i) { cout << i << endl; });
    selectSort(arr, 10, [](int x, int y) -> int { return x > y; });
    for_each(arr, arr + 10, [](int &i) { cout << i << endl; });
    return 0;
}