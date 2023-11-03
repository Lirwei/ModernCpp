#include <iostream>
#include <unordered_map>

using namespace std;

// unordered_map 采用 HashMap（链地址法：数组+链表） 的数据结构

int main() {
    unordered_map<string, string> map = {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}
    };

    for (auto &m: map) {
        cout <<"{ key: " << m.first << ", value: " << m.second << " }" << endl;
    }

    map["black"] = "#000000";
    map["white"] = "#FFFFFF";

    cout << map.size() << endl;
    cout << map["black"] << endl;

    return 0;
}