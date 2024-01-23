#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> table;
int height;
vector<vector<int>> Graph;
vector<int> timeIn, timeOut;
int cnt_time;

void inicjalizacja(int n) {
    height = (int)ceil(log2(n));
    table.resize(n + 1, vector<int>(height + 1, -1));
    Graph.resize(n + 1);
    timeIn.resize(n + 1);
    timeOut.resize(n + 1);
    cnt_time = 0;
}

void dfs(int s, int p) {
    table[s][0] = p;
    timeIn[s] = ++cnt_time;
    for (int i = 1; i <= height; i++)
        table[s][i] = table[table[s][i - 1]][i - 1];
    for (int child : Graph[s]) {
        if (child == p) continue;
        dfs(child, s);
    }

    timeOut[s] = ++cnt_time;
}

bool sprawdz(int u, int v) {
    return timeIn[u] <= timeIn[v] && timeOut[u] >= timeOut[v];
}

int lca(int U, int V) {
    if (sprawdz(U, V)) return U;

    if (sprawdz(V, U)) return V;

    for (int i = height; i >= 0; i--) {
        if (!sprawdz(table[U][i], V)) U = table[U][i];
    }

    return table[U][0];
}

bool czy_jest(int U, int V, int R) {
    dfs(1, 1);
    int LCA = lca(U, V);
    int LCA_1 = lca(U, R);
    int LCA_2 = lca(V, R);

    if (LCA == R || (LCA_1 == LCA && LCA_2 == R) ||
        (LCA_2 == LCA && LCA_1 == R)) {
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_miast, skad, dokad, il_zapytan, miasto_szukane;
    cin >> il_miast;
    inicjalizacja(1e5 + 1);
    for (int i = 0; i < il_miast - 1; i++) {
        cin >> skad >> dokad;
        Graph[skad].push_back(dokad);
    }
    cin >> il_zapytan;
    for (int i = 0; i < il_zapytan; i++) {
        cin >> skad >> dokad >> miasto_szukane;
        if (czy_jest(skad, dokad, miasto_szukane))
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}
