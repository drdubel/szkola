#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 2e4 + 7;
int tarasy[MAXN], il_tarasow, il_kredytow, wyn, pocz, koszt, kon, i;

int rozwiaz() {
    kon = 0;
    koszt = 0;
    for (pocz = 0; pocz < il_tarasow; pocz++) {
        while (kon < pocz && il_kredytow < koszt) {
            il_kredytow += max(0, tarasy[kon + 1] - tarasy[kon]);
            kon++;
        }
        if (koszt <= il_kredytow) {
            wyn = max(pocz - kon + 1, wyn);
        }
        il_kredytow -= max(0, tarasy[pocz + 1] - tarasy[pocz]);
    }
    return wyn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_tarasow >> il_kredytow;
    for (int i = 0; i < il_tarasow; i++) {
        cin >> tarasy[i];
    }
    wyn = rozwiaz();
    reverse(tarasy, tarasy + il_tarasow);
    cout << rozwiaz();
}
