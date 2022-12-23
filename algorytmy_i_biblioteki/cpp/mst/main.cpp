#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int maxn = 1000007;
int ojc[maxn];

int Find(int v) {
    if (v == ojc[v])
        return v;
    else {
        ojc[v] = Find(ojc[v]);
        return ojc[v];
    }
}

void Union(int a, int b) {
    Find(a);
    Find(b);
    ojc[ojc[a]] = ojc[b];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    vector<int> v(4);
    int i;
    for (i = 1; i <= n; ++i) ojc[i] = i;
    for (i = 1; i <= m; ++i) {
        scanf("%d%d%d", &(v[2]), &(v[3]), &(v[0]));
        v[1] = i;
        q.push(v);
    }
    while (!q.empty()) {
        v = q.top();
        q.pop();
        if (Find(v[2]) != Find(v[3])) {
            printf("%d\n", v[1]);
            Union(v[2], v[3]);
        }
    }
}