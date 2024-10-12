#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main() {
    string stroka;
    getline(cin, stroka);

    long long num = 0;
    bool isNumber = false;
    bool isPlus = false;
    bool isMinus = false;

    for (char c : stroka) {
        if (c == '+') {
            isPlus = true;
        }
        else if (c == '-') {
            isMinus = true;
        }
        else if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            isNumber = true;
        }
        else {
            break;
        }
    }

    if (isMinus) {
        num = -num;
    }

    if (isNumber) {
        if (num < INT_MIN || num > INT_MAX) {
            cout << "" << endl;
        }
        else {
            cout << static_cast<int>(num) << endl;
        }
    }
    else {
        cout << "" << endl;
    }

    return 0;
}