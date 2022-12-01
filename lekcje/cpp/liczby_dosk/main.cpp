#include <cmath>
#include <iostream>
using namespace std;

int suma_dzielnikow(int liczba) {
    int suma_dziel = 0;
    for (int i = 1; i <= sqrt(liczba); i++) {
        if (liczba % i == 0) {
            suma_dziel += i;
            if (liczba / i != i) {
                suma_dziel += liczba / i;
            }
        }
    }
    return suma_dziel - liczba;
}

int main() {
    int liczba;
    cin >> liczba;
    int suma_dziel = suma_dzielnikow(liczba);
    if (liczba == suma_dziel) {
        cout << "TAK\n";
    } else {
        cout << suma_dziel << "\n";
    }
}
