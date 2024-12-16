#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

constexpr unsigned int MAXN = 2e5 + 7;

pair<int, int> stacje_metra[MAXN];
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

    int n, t, a, b;

    cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        cin >> stacje_metra[i].first >> stacje_metra[i].second;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (stacje_metra[i].first == stacje_metra[j].first ||
                stacje_metra[i].second == stacje_metra[j].second) {
                polaczenia[i + 1].push_back(j + 1);
                polaczenia[j + 1].push_back(i + 1);
            }
        }
    }

    for (int i = 0; i < t; ++i) {
        cin >> a >> b;

        dfs(a);

        if (odwiedzony[b])
            cout << "TAK\n";
        else
            cout << "NIE\n";

        memset(odwiedzony, false, n);
    }
}