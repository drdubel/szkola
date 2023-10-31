#include <iostream>
#include <vector>
using namespace std;

const unsigned int MAXN = 1e6 + 7;
unsigned int il_wierzcholkow, il_krawedzi, pocz, a, b, i;

vector<unsigned int> polaczenia[MAXN];
bool odwiedzony[MAXN];

void dfs(int k) {
    odwiedzony[k] = 1;
    for (int wierzcholek : polaczenia[k])
        if (!odwiedzony[wierzcholek]) dfs(wierzcholek);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_wierzcholkow >> il_krawedzi;
    for (i = 0; i < il_krawedzi; i++) {
        cin >> a >> b;
        polaczenia[a].push_back(b);
        polaczenia[b].push_back(a);
    }
    dfs(1);
    for (i = 1; i <= il_wierzcholkow; i++) {
        if (odwiedzony[i]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
}