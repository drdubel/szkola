#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 3e4 + 7;
int bierki[MAXN], il_bierek, dl_bierki, pocz, kon = 2, wyn, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_bierek;
    for (i = 0; i < il_bierek; ++i) cin >> bierki[i];
    sort(bierki, bierki + il_bierek);
    while (pocz < il_bierek) {
        while ((bierki[pocz] + bierki[pocz + 1] > bierki[kon + 1]) &&
               (kon < il_bierek - 1))
            ++kon;
        wyn = max(kon - pocz + 1, wyn);
        ++pocz;
    }
    cout << wyn << "\n";
}