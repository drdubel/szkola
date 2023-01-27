#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
long long res[2], n, a, b, c, d;

void FastDoubling(long long n, long long res[]) {
    if (n == 0) {
        res[0] = 0;
        res[1] = 1;
        return;
    }
    FastDoubling((n / 2), res);
    a = res[0];
    b = res[1];

    c = 2 * b - a;

    if (c < 0) c += MOD;
    c = (a * c) % MOD;
    d = (a * a + b * b) % MOD;
    if (n % 2 == 0) {
        res[0] = c;
        res[1] = d;
    } else {
        res[0] = d;
        res[1] = c + d;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    FastDoubling(n, res);

    cout << res[0] << "\n";
}