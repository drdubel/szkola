#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr long long INF = 0xfffffffffffffff;
constexpr long long MAXN = 5e5 + 7;
vector<pair<long long, long long>> graph[MAXN];

vector<long long> dijkstra(long long n, long long source) {
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        pqueue;

    pqueue.push({0, source});
    dist[source] = 0;

    while (!pqueue.empty()) {
        long long u = pqueue.top().second;
        pqueue.pop();

        for (pair<long long, long long> child : graph[u]) {
            long long alt = dist[u] + child.second;

            if (alt < dist[child.first]) {
                dist[child.first] = alt;
                pqueue.push({dist[child.first], child.first});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, a, b, w;
    cin >> n >> m;

    for (long long i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        --a;
        --b;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    for (long long dist : dijkstra(n, 0)) {
        cout << (dist != INF ? dist : -1) << "\n";
    }
}