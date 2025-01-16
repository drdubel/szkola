#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using para = pair<int, int>;

const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;

vector<para> edges(MAX);
vector<int> visited(MAX, 0);

void dfs(int node, int group) {
    visited[node] = group;
    int nextNode = edges[node].second;
    if (!visited[nextNode]) {
        dfs(nextNode, group);
    }
}

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> edges[i].first;
    }

    for (int i = 0; i < n; ++i) {
        cin >> edges[i].second;
    }

    sort(edges.begin(), edges.begin() + n);

    int groupCount = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, ++groupCount);
        }
    }

    ll result = mod_exp(2, groupCount, MOD);
    cout << result << "\n";

    return 0;
}
