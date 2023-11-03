#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

// range-based for

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        cout << arr[i] << "\t";
    cout << endl;

    for (auto &n: arr) {
        n += 5;
    }

    for (auto n: arr)
        cout << n << "\t";
    cout << endl;

    char *p = "China"; // for (auto& c : p) 不可用
    char buf[] = "China";

    for (auto &c: buf)
        cout << c << '\t';
    cout << endl;

    vector<int> vi(arr, arr + 10);
    for (auto &k: vi)
        cout << k << '\t';
    cout << endl;

    list<int> li(arr, arr + 10);
    for (auto &k: li)
        cout << k << '\t';
    cout << endl;

    map<int, string> mis;
    mis[0] = "China";
    mis[1] = "America";
    mis.insert({100, "Canada"});

    map<int, string>::iterator itr;
    for (itr = mis.begin(); itr != mis.end(); ++itr) {
        cout << itr->first << ": " << itr->second << endl;
    }

    for (auto &i: mis) {
        cout << i.first << ": " << i.second << endl;
    }

    return 0;
}