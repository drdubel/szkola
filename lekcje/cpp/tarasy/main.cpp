#include <iostream>

using namespace std;

const int MAXN = 2e4 + 7;
int tarasy[MAXN], odl[MAXN], odw_odl[MAXN], il_tarasow, il_kredytow, wyn, pocz,
    koszt, kon, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_tarasow >> il_kredytow;
    cin >> tarasy[0];
    odl[0] = tarasy[0];
    for (i = 1; i < il_tarasow; ++i) {
        cin >> tarasy[i];
        odl[i] = max(tarasy[i - 1] - tarasy[i], 0);
    }
    for (i = il_tarasow - 1; i > 0; --i) {
        odw_odl[i] = max(tarasy[i - 1] - tarasy[i], 0);
    }
    while (pocz < il_tarasow) {
        while ((koszt <= il_kredytow) && (kon < il_tarasow - 1)) {
            ++kon;
            koszt += odl[kon];
        }
        ++pocz;
        koszt -= odl[pocz];
        wyn = max(kon - pocz + 1, wyn);
    }
    pocz = il_tarasow - 1;
    kon = il_tarasow - 1;
    while (pocz > 0) {
        while ((koszt <= il_kredytow) && (kon > 0)) {
            --kon;
            koszt += odw_odl[kon];
        }
        --pocz;
        koszt -= odw_odl[pocz];
        wyn = max(pocz - kon + 1, wyn);
    }
    cout << wyn << "\n";
}