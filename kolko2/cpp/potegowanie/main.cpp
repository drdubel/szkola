#include <iostream>

using namespace std;

long long mod, x, n;
__int128_t a;

__int128_t pot(__int128_t x, __int128_t n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        a = pot(x, n / 2);
        return (__int128_t)(a * a) % mod;
    } else
        return ((x % mod) * pot(x, n - 1) % mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> n >> mod;
    cout << (long long)pot(x, n) << "\n";
}
