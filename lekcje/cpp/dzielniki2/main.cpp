#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool czy_pierwsza(long long liczba) {
    for (long long i = 2; i < sqrt(liczba); i++) {
        if (liczba % i == 0) {
            return false;
        }
    }
    return true;
}

pair<long long, long long> znajdz_pierwsze_dzielniki(long long liczba1,
                                                     long long liczba2) {
    for (long long i = ceil(sqrt(min(liczba1, liczba2))); i > 0; i--) {
        if ((liczba1 % i == 0) & (liczba2 % (i * i) == 0) & (czy_pierwsza(i))) {
            return {i, i * i};
        }
        if ((liczba1 % i == 0) & (liczba2 % i == 0) & (czy_pierwsza(i))) {
            return {i, i};
        }
        if ((liczba1 % i == 0) & (liczba2 % (i * i) == 0) &
            (czy_pierwsza(liczba1 / i))) {
            return {i, i * i};
        }
        if ((liczba1 % i == 0) & (liczba2 % i == 0) &
            (czy_pierwsza(liczba1 / i))) {
            return {i, i};
        }
    }
    return {1, 1};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long il_zapytan, liczba1, liczba2;
    cin >> il_zapytan;
    for (long long i = 0; i < il_zapytan; i++) {
        cin >> liczba1 >> liczba2;
        pair<long long, long long> poprzednie_dzielniki =
            znajdz_pierwsze_dzielniki(liczba1, liczba2);
        liczba1 /= poprzednie_dzielniki.first;
        liczba2 /= poprzednie_dzielniki.second;
        pair<long long, long long> dzielniki =
            znajdz_pierwsze_dzielniki(liczba1, liczba2);
        while (poprzednie_dzielniki != dzielniki) {
            liczba1 /= dzielniki.first;
            liczba2 /= dzielniki.second;
            poprzednie_dzielniki = dzielniki;
            dzielniki = znajdz_pierwsze_dzielniki(liczba1, liczba2);
        }
        cout << liczba1 << ' ' << liczba2 << "\n";
    }
}