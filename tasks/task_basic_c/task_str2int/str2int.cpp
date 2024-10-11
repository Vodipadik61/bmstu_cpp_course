#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string stroka;
    getline(cin, stroka);

    istringstream is(stroka);
    int num;
    if (is >> num) {
        cout << num << endl;
    }
    else {
        cout << "" << endl; 
    }

    return 0;
}