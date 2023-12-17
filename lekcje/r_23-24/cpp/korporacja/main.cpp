#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 5e5 + 7;
int pre[MAXN], post[MAXN], c = 1;
vector<int> graph[MAXN];

void dfs(int v, int p) {
    pre[v] = c++;
    for (auto u : graph[v])
        if (u != p) dfs(u, v);
    post[v] = c++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, x;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        cin >> x;
        graph[x].push_back(i);
        graph[i].push_back(x);
    }

    dfs(0, 0);

    while (true) {
        cin >> a;

        if (a == -1) break;

        cin >> b;

        if (pre[a] < pre[b] && post[b] < post[a])
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}