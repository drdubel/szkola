#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

constexpr int MAXN = 3e5 + 7;

pair<int, int> arr[MAXN];
int act[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    long long res = 0;

    cin >> n >> m;

    vector<multiset<int>> G(m + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].second;
    }

    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; ++i) {
        act[i] = arr[i].second;
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            G[i].insert(x);
        }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            auto curr = G[i].lower_bound(act[j]);

            if (curr == G[i].end()) {
                cout << "NIE\n";
                return 0;
            }

            act[j] = *curr;
            G[i].erase(curr);
        }

    for (int i = 1; i <= n; ++i)
        res += (long long)(act[i] - arr[i].second) * (long long)arr[i].first;

    cout << res << "\n";
}