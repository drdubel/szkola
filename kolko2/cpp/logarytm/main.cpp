#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

long long a, c, p, i;

int logarytm() {
    a %= p, c %= p;
    int n = sqrt(p) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i) an = (an * 1ll * a) % p;

    unordered_map<int, int> wartosci;
    for (int i = 0, akt = c; i <= n; ++i) {
        wartosci[akt] = i;
        akt = (akt * 1ll * a) % p;
    }

    for (int i = 1, akt = 1; i <= n; ++i) {
        akt = (akt * 1ll * an) % p;
        if (wartosci.count(akt)) {
            int ans = n * i - wartosci[akt];
            return ans;
        }
    }
    return -1;
}

int main() {
    while (cin >> a >> c >> p) cout << logarytm() << "\n";
}