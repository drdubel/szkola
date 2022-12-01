#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string dodawanie(string liczba1, string liczba2, int dl_liczb) {
    int suma;
    int przeniesione = 0;
    string wynik = "";
    for (int i = dl_liczb - 1; i >= 0; i--) {
        suma = przeniesione + (int)(liczba1[i] - '0') + (int)(liczba2[i] - '0');
        wynik += '0' + (char)(suma % 10);
        przeniesione = suma / 10;
    }
    if (suma / 10 != 0) {
        wynik += '0' + (char)(suma / 10);
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

int main() {
    string liczba1;
    string liczba2;
    cin >> liczba1;
    cin >> liczba2;
    int dl_liczby1 = liczba1.size();
    int dl_liczby2 = liczba2.size();
    int dl_liczb = max(dl_liczby1, dl_liczby2);
    string wynik = dodawanie(liczba1, liczba2, dl_liczb);
    cout << wynik;
    cout << '\n';
}
