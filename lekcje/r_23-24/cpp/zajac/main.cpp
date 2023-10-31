#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int z_maks_kapust(int maks_skok, int n, int w, pair<int, int> *kapusty,
                  bool *odwiedzone, int maks_kapust = 1) {
    for (int i = 0; i < n; ++i) {
        if (odwiedzone[i]) continue;
        if (maks_skok >=
            sqrt(pow(abs(kapusty[i].first - kapusty[w].first), 2) +
                 pow(abs(kapusty[i].second - kapusty[w].second), 2))) {
            odwiedzone[i] = true;
            maks_kapust =
                max(maks_kapust, z_maks_kapust(maks_skok, n, i, kapusty,
                                               odwiedzone, maks_kapust + 1));
        }
    }
    return maks_kapust;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, maks_skok;
    cin >> n >> maks_skok;

    pair<int, int> kapusty[n];
    bool odwiedzone[n];
    memset(odwiedzone, false, sizeof(odwiedzone));

    for (int i = 0; i < n; ++i) {
        cin >> kapusty[i].first >> kapusty[i].second;
    }

    odwiedzone[0] = true;
    cout << z_maks_kapust(maks_skok, n, 0, kapusty, odwiedzone) << "\n";
}