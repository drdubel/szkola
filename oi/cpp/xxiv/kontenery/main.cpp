#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 105000;

int kontenery[MAXN];
int pref[MAXN];

vector<pair<int, int>> q[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, p, a, l, d;

    cin >> n >> k;

    p = sqrt(n);

    for (int i = 1; i <= k; i++) {
        cin >> a >> l >> d;
        if (d >= p)
            for (int j = a; l > 0; l--, j += d) kontenery[j]++;
        else
            q[d].push_back({a, l});
    }

    for (int skok = 1; skok < p; skok++) {
        for (int i = 1; i <= n; i++) pref[i] = 0;

        for (int i = 0; i < q[skok].size(); i++) {
            a = q[skok][i].first, l = q[skok][i].second;
            pref[a]++;
            pref[a + skok * l]--;
        }

        for (int i = 1; i <= skok; i++) {
            int current = 0;
            for (int j = i; j <= n; j += skok) {
                current += pref[j];
                kontenery[j] += current;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << kontenery[i] << " ";
}