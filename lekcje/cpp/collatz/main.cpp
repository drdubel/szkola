#include <iostream>

using namespace std;

int main() {
    int liczba;
    cin >> liczba;
    while (liczba > 1) {
        cout << liczba << ' ';
        if (liczba % 2 == 0) {
            liczba /= 2;
        } else {
            liczba = liczba * 3 + 1;
        }
    }
    cout << liczba << "\n";
}