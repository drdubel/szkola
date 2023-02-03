#include <iostream>

using namespace std;

const int MAXN = 2e4 + 7;
int tarasy[MAXN], il_tarasow, il_kredytow, wyn, pocz, koszt, kon, i;

int rozwiaz() {
    int wynik = 0;
    int kon = 0;
    int koszt = 0;
    for (int pocz = 0; pocz < il_tarasow; pocz++) {
        while (kon < pocz && koszt > il_kredytow) {
            koszt -= max(0, tarasy[kon + 1] - tarasy[kon]);
            kon++;
        }
        if (koszt <= il_kredytow) {
            wynik = max(pocz - kon + 1, wynik);
        }
        koszt += max(0, tarasy[pocz + 1] - tarasy[pocz]);
    }
    return wynik;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_tarasow >> il_kredytow;
    for (int i = 0; i < il_tarasow; i++) {
        cin >> tarasy[i];
    }
    wyn = rozwiaz();

    for (int i = 0; i < il_tarasow / 2; i++) {
        swap(tarasy[i], tarasy[il_tarasow - i - 1]);
    }
    cout << max(wyn, rozwiaz());
}
