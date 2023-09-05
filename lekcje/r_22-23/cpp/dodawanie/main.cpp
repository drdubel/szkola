#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string dodawanie(string liczba1, string liczba2) {
    int suma, dl_krotsza, dl_dluzsza, przeniesione = 0,
                                      dl_liczby1 = liczba1.size(),
                                      dl_liczby2 = liczba2.size();
    dl_krotsza = min(dl_liczby1, dl_liczby2);
    dl_dluzsza = max(dl_liczby1, dl_liczby2);
    string wynik;
    for (int i = dl_dluzsza - dl_krotsza; i > 0; i--) {
        if (dl_liczby1 < dl_liczby2) {
            liczba1 = "0" + liczba1;
        } else {
            liczba2 = "0" + liczba2;
        }
    }
    for (int i = dl_dluzsza - 1; i >= 0; i--) {
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
    string liczba1, liczba2;
    cin >> liczba1 >> liczba2;
    string wynik = dodawanie(liczba1, liczba2);
    cout << wynik << "\n";
}