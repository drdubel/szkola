#include <algorithm>
#include <iostream>

using namespace std;

struct pol {
    int cena = 1, pion = 0;
};

bool wez_wieksza(pol a, pol b) { return a.cena > b.cena; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, cena_og = 0, pionowe = 1, poziome = 1;
    cin >> m >> n;
    pol pols[n + m - 2];
    for (int i = 0; i < m - 1; ++i) {
        cin >> pols[i].cena;
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> pols[m + i - 1].cena;
        pols[m + i - 1].pion = 1;
    }
    sort(pols, pols + n + m - 2, wez_wieksza);
    for (int i = 0; i < m + n - 2; ++i) {
        if (pols[i].pion == 0) {
            pionowe++;
            cena_og += poziome * pols[i].cena;
        } else {
            poziome++;
            cena_og += pionowe * pols[i].cena;
        }
    }
    cout << cena_og;
}