#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll pot(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        ll a = pot(x, n / 2);
        return (ll)(a * a) % MOD;
    } else
        return ((x % MOD) * pot(x, n - 1) % MOD) % MOD;
}

int main() {
    int x, n, q, wynik;

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &x, &n);
        wynik = pot(x, n);
        printf("%d\n", wynik);
    }
}
