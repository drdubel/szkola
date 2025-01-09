#include <cmath>
#include <iostream>

using namespace std;

constexpr int MAXN = 5e5 + 7;
int uczniowie[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, min_glod = 2e9, max_glod = 0;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> uczniowie[i];

        min_glod = min(min_glod, min(k - uczniowie[i] % k, uczniowie[i] % k));
        max_glod = max(max_glod, min(k - uczniowie[i] % k, uczniowie[i] % k));
    }

    cout << (int)ceil((long double)(max_glod - min_glod) / 2) << "\n";
}