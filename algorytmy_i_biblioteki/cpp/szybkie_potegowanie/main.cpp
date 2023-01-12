#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll wynik;

ll pot(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return pow(pot(x, n / 2), 2);
    else return pot(x, n - 1) * x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll il_poteg, x, n;
    cin >> il_poteg;
    for (ll i = 0; i < il_poteg; i++) {
        cin >> x >> n;
        cout << pot(x, n) << "\n";
    }
}