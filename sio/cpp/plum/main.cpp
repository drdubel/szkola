#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool znajdz7(string liczba) {
    for (int i = 0; i < liczba.size(); i++) {
        if (liczba[i] == '7') {
            return true;
        }
    }
    return false;
}


int main() {
    int a, b;
    cin >> a >> b;
    for (a; a <= b; a++) {
        string a_str = to_string(a);
        if (a%7 == 0 || znajdz7(a_str)) {
            cout << "plum\n";
        } else {
            cout << a << "\n";
        }
    }
}
