#include <iostream>
using namespace std;

int main() {
    int rok;
    cin >> rok;
    if (rok % 4 == 0) {
        if (rok % 100 == 0 and rok % 400 != 0) {
            cout << "NIE";
        } else {
            cout << "TAK";
        }
    } else {
        cout << "NIE";
    }
    cout << "\n";
}