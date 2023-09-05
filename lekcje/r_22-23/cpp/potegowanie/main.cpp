#include <cmath>
#include <iostream>

typedef long long ll;

using namespace std;

const ll MAXN = 1e7 + 7;
ll n, a, b;
ll wynik;

ll pot(ll x, ll n) {
    x %= MAXN;
    if (n == 0) return 1;
    if (n % 2 == 0)
        return (ll)pow(pot(x, n / 2) % MAXN, 2) % MAXN;
    else
        return (pot(x, n - 1) % MAXN * x) % MAXN;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << pot(a, b) << "\n";
    }
}