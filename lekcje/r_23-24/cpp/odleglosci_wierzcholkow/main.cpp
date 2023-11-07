#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e6 + 7;
vector<int> graf[MAXN];
int odl[MAXN], il_krawedzi, il_wierzcholkow, a, b, i;

void bfs(int x) {
    memset(odl, -1, MAXN);
    odl[x] = 0;
    queue<int> kolejka;
    kolejka.push(x);
    while (!kolejka.empty()) {
        x = kolejka.front();
        kolejka.pop();
        for (int k : graf[x]) {
            if (odl[k] == -1) {
                odl[k] = odl[x] + 1;
                kolejka.push(k);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_wierzcholkow >> il_krawedzi;
    for (i = 0; i < il_krawedzi; ++i) {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    bfs(1);
    for (i = 1; i <= il_wierzcholkow; ++i) {
        cout << odl[i] << "\n";
    }
}