#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 5e6 + 7;
int drewno[MAXN], wystapienia[2 * MAXN];
bitset<MAXN> dp;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, wynik = 0, suma_dlugosci = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> drewno[i];
        suma_dlugosci += drewno[i];
        ++wystapienia[drewno[i]];
    }

    sort(drewno, drewno + n);

    int najdluzszy = drewno[n - 1];
    drewno[n - 1] = 0;
    wystapienia[najdluzszy]--;
    --n;

    suma_dlugosci -= najdluzszy;

    for (int i = 1; i <= suma_dlugosci; ++i) {
        if (wystapienia[i] > 2) {
            int tmp = 2 - (wystapienia[i] % 2);
            wystapienia[2 * i] += (wystapienia[i] - tmp) / 2;
            wystapienia[i] = tmp;
        }
        for (int j = 0; j < wystapienia[i]; ++j) v.push_back(i);
    }

    dp[0] = 1;
    for (int i : v) dp |= (dp << i);

    for (int i = 0; i <= suma_dlugosci / 2; ++i)
        if (dp[i]) wynik = i;

    cout << najdluzszy + wynik;
}
