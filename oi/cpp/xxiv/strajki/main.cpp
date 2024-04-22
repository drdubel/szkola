#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 5e5 + 7;

vector<int> graf[MAXN];
int parent[MAXN], ans = 1, n, q, strajk[MAXN], children[MAXN];

void dfs(int v, int p) {
    parent[v] = p;
    for (int u : graf[v])
        if (u != p) dfs(u, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int v, u;

        cin >> v >> u;

        graf[v].push_back(u);
        graf[u].push_back(v);
    }

    dfs(1, 1);

    children[1] = graf[1].size();

    for (int i = 2; i <= n; i++) {
        children[i] = graf[i].size() - 1;
    }

    cin >> q;

    for (int i = 1; i <= q; i++) {
        int v;

        cin >> v;

        if (v > 0) {
            strajk[v] = 1;
            int a = children[v];

            if (v != 1 && strajk[parent[v]] == 0) {
                a++;
            }
            if (v != 1) {
                children[parent[v]]--;
            }

            ans += a - 1;
            cout << ans << "\n";
        } else {
            v *= -1;
            strajk[v] = 0;
            int a = children[v];

            if (v != 1 && strajk[parent[v]] == 0) {
                a++;
            }
            if (v != 1) {
                children[parent[v]]++;
            }

            ans -= a - 1;
            cout << ans << "\n";
        }
    }
}