#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string stroka;
    getline(cin, stroka);

    istringstream isstr(stroka);
    int num;
    if (isstr >> num) {
        cout << num << endl;
    }
    else {
        cout << "" << endl; 
    }

    return 0;

}