#include <iostream>

using namespace std;

int main() {

    float hignrate = 0.3;
    float hignbase = 30000;

    auto high = [hignrate, hignbase](double money) {
        return (money - hignbase) * hignrate;
    };

    float middlerate = 0.2;
    float middlebase = 15000;
    auto midlle = [middlerate, middlebase](double money) {
        return (money - middlebase) * middlerate;
    };

    float lowrate = 0.2;
    float lowbase = 15000;
    auto low = [lowrate, lowbase](double money) {
        return (money - lowbase) * lowrate;
    };

    cout << "请输入你的收入：";
    double salary;
    cin >> salary;

    if (salary > 30000)
        cout << high(salary) << endl;
    else if (salary > 15000)
        cout << midlle(salary) << endl;
    else
        cout << low(salary) << endl;
}

#if 0
// functor
class Tax {
    public:
        Tax(float r, float b) : _rate(r), _base(b) {}
        float operator()(float money) {
            return (money - _base) * _rate;
        }
    private:
        float _rate;
        float _base;
};

int main() {
    Tax high(0.3, 30000);
    Tax midlle(0.2, 15000);
    Tax low(0.1, 3500);

    cout << "请输入你的收入：";
    double salary;
    cin >> salary;
    if (salary > 30000)
        cout << high(salary) << endl;
    else if (salary > 15000)
        cout << midlle(salary) << endl;
    else
        cout << low(salary) << endl;
    return 0;
}
#endif