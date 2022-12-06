#include <cmath>
#include <iostream>

using namespace std;

#define MAX 1000000

int czy_pierwsza[MAX];

void sito_erastotenesa() {
    czy_pierwsza[1] = 1;
    for (int i = 2; i < MAX; i++) czy_pierwsza[i] = i;

    for (int i = 4; i < MAX; i += 2) czy_pierwsza[i] = 2;

    for (int i = 3; i * i < MAX; i++) {
        if (czy_pierwsza[i] == i) {
            for (int j = i * i; j < MAX; j += i)
                if (czy_pierwsza[j] == j) czy_pierwsza[j] = i;
        }
    }
}

int nwd_pierwsze(int liczba1, int liczba2) {
    while (liczba1) {
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sito_erastotenesa();
    long long il_zapytan, liczba1, liczba2;
    cin >> il_zapytan;
    for (long long i = 0; i < il_zapytan; i++) {
        cin >> liczba1 >> liczba2;
        cout << nwd_pierwsze(liczba1, liczba2) << "\n";
    }
}