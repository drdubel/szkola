#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 1e6 + 7;
int n, i, t, q, j, m, k, ind;
bool score;
vector<int> pos[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> t;
        pos[t].push_back(i);
    }

    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> m;
        ind = 0;
        score = 0;
        for (j = 0; j < m; ++j) {
            cin >> t;
            auto l = pos[t].begin();
            auto r = pos[t].end();
            auto found = lower_bound(l, r, ind);
            if (found == r)
                score = 1;
            else
                ind = (*found) + 1;
        }
        score ? cout << "NIE" : cout << "TAK";
        cout << '\n';
    }
}