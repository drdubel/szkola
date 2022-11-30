#include <cmath>
#include <iostream>

using namespace std;

#define MAX 1000001

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

void rozklad(int liczba_rozkladana) {
    while (liczba_rozkladana > 1) {
        cout << czy_pierwsza[liczba_rozkladana] << ' ';
        liczba_rozkladana /= czy_pierwsza[liczba_rozkladana];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sito_erastotenesa();
    int il_liczb, liczba_do_rozkladu;
    cin >> il_liczb;
    for (int i = 0; i < il_liczb; i++) {
        cin >> liczba_do_rozkladu;
        rozklad(liczba_do_rozkladu);
        cout << "\n";
    }
}