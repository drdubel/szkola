#include <iostream>

using namespace std;

void rysuj(int wielkosc) {
    int i;
    for (i = 1; i <= wielkosc; i++) {
        cout << string(wielkosc + 1 - i, ' ') << string(i * 2 - 1, '*') << "\n";
    }
    for (i = 1; i <= wielkosc + 1; i++) {
        cout << string(wielkosc + 1 - i, ' ') << string(i * 2 - 1, '*') << "\n";
    }
    cout << string(wielkosc, ' ') << '*' << "\n"
         << string(wielkosc, ' ') << '*' << "\n";
}

int main() {
    int wielkosc_choinki;
    cin >> wielkosc_choinki;
    rysuj(wielkosc_choinki);
}