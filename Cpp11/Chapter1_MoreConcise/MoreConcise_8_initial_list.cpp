#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<int> vi;
    // vector<int> vi(10);
    // vector<int> vi(10, 101);
    // vector<int> vi(arr, arr+10);
    // vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8};

    // list<int> vi;
    // list<int> vi(10);
    // list<int> vi(10, 101);
    // list<int> vi(arr, arr+10);
    // list<int> vi = {1, 2, 3, 4, 5, 6, 7, 8};

    // for (auto i : vi) {
    //     cout << i << endl;
    // }

    map<int, string> mis = {
        {1, "China"},
        {2, "America"},
        {3, "Canada"}
    };

    // mis[0] = "China";
    // mis[1] = "America";
    // mis[2] = "Canada";

    // mis.insert(make_pair<int, string>(1, "China"));
    // mis.insert(make_pair<int, string>(2, "America"));
    // mis.insert(make_pair<int, string>(3, "Canada"));

    // mis.insert(map<int, string>::value_type(1, "China"));
    // mis.insert(map<int, string>::value_type(2, "America"));
    // mis.insert(map<int, string>::value_type(3, "Canada"));
    mis.insert(pair<int, string>(4, "fourth"));

    for (auto &i: mis) {
        cout << i.first << ": " << i.second << endl;
    }

    return 0;
}