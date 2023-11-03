#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> mis;
    mis.insert(map<int, string>::value_type(1, "China")); // int[0]

    typedef decltype(map<int, string>::value_type()) mapair;
    mis.insert(mapair(2, "American"));
    for (auto &item: mis) {
        cout << item.first << ":" << item.second << endl;
    }

    return 0;
}