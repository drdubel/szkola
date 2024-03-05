#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MAXN = 5e6 + 7;
int drewno[MAXN], dp[MAXN];

void zmiesc(int n, int pojemnosc) {
    for (int i = 1; i <= n; i++)
        for (int w = pojemnosc; w > drewno[i - 1] - 1; w--)
            dp[w] = max(dp[w], dp[w - drewno[i - 1]] + drewno[i - 1]);
}

int main() {
    int n, wynik = 0, suma_dlugosci = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &drewno[i]);
        suma_dlugosci += drewno[i];
    }

    sort(drewno, drewno + n);

    int najdluzszy = drewno[n - 1];
    drewno[n - 1] = 0;
    --n;

    suma_dlugosci -= najdluzszy;
    int pojemnosc = suma_dlugosci / 2;

    zmiesc(n, pojemnosc);

    printf("%d\n", najdluzszy + dp[pojemnosc]);
}
