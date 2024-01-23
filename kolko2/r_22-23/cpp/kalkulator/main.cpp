#include <iostream>
using namespace std;

typedef long long ll;
ll mod, out = 0;

ll pow(ll a, ll b) {
    if (b == 0)
        return 1;
    else if (b == 1)
        return a % mod;
    if (b % 2 == 0)
        return pow(a * a % mod, b / 2) % mod;
    else
        return pow(a * a % mod, b / 2) * a % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> mod;
    char d;
    ll i;
    while (cin >> d >> i) {
        if (d == '+') {
            if (i >= 0)
                out = (out + i) % mod;
            else {
                i = -i;
                out = ((out % mod - i % mod) % mod + mod) % mod;
            }
        } else if (d == '-') {
            if (i >= 0)
                out = ((out % mod - i % mod) % mod + mod) % mod;
            else {
                i = -i;
                out = (out + i) % mod;
            }
        } else if (d == '*')
            out = ((i * out) % mod + mod) % mod;
        else
            out = ((((out)*pow(i, mod - 2)) % mod + mod) % mod);
    }
    cout << out;
}