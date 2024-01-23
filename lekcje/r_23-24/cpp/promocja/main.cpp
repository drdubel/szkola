#include <iostream>
#include <map>

#include "cprolib.h"
using namespace std;

constexpr int MAXN = 3e5 + 7;
map<int, int> ludzie[MAXN];
int miasta[MAXN];

int rozwiaz(int x, int y) {
    auto p = ludzie[x].upper_bound(y);
    --p;
    return p->second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, z, x, y;
    inicjuj(&n, &m, &z);

    for (int i = 1; i <= n; i++) {
        miasta[i] = i;
        ludzie[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        pobierz_promocje(i, &x, &y);

        int personB = miasta[y];
        int personA = miasta[x];
        swap(miasta[x], miasta[y]);
        ludzie[personA][i] = y;
        ludzie[personB][i] = x;
    }
    for (int i = 0; i < z; i++) {
        pobierz_zapytanie(&x, &y);
        odpowiedz(rozwiaz(x, y));
    }
}
