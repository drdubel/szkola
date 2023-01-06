#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

long long a, c, p, akt;
int i;

int logarytm() {
    a %= p, c %= p;
    int n = sqrt(p) + 1;

    long long an = 1;
    for (i = 0; i < n; ++i) an = (an * a) % p;

    unordered_map<int, int> wartosci;
    for (i = 0, akt = c; i <= n; ++i) {
        wartosci[akt] = i;
        akt = (akt * a) % p;
    }

    for (i = 1, akt = 1; i <= n; ++i) {
        akt = (akt * an) % p;
        if (wartosci[akt]) {
            int ans = n * i - wartosci[akt];
            return ans;
        }
    }
    return -1;
}

int main() {
    while (cin >> a >> c >> p) cout << logarytm() << "\n";
}