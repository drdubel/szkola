#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_zwiazkow, i, min, max, maks_il_zwiazkow = 0, wynik = 0;
    cin >> il_zwiazkow;
    pair<int, int> temperatury[il_zwiazkow * 2];
    for (i = 0; i < il_zwiazkow * 2; i += 2) {
        cin >> min >> max;
        temperatury[i] = make_pair(min, 0);
        temperatury[i + 1] = make_pair(max, 1);
    }
    sort(temperatury, temperatury + il_zwiazkow * 2);
    for (i = 0; i < il_zwiazkow * 2; i++) {
        if (temperatury[i].second == 1) {
            wynik++;
        } else if (wynik > 0) {
            wynik--;
        }
        if (wynik > maks_il_zwiazkow) {
            maks_il_zwiazkow = wynik;
        }
    }
    cout << maks_il_zwiazkow << "\n";
}
