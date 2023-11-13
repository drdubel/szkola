#include <iostream>
#include <vector>

using namespace std;

int n, m;

void licz_odleglosci(vector<int>* bitmapa, vector<int>* odleglosci,
                     int odl_od_jedynki, int i, int j, int mod1, int mod2) {
    if (bitmapa[i][j] == 1)
        odl_od_jedynki = 0;
    else
        ++odl_od_jedynki;
    odleglosci[i][j] = min(odl_od_jedynki, odleglosci[i][j]);

    if (i + mod1 < n && i + mod1 >= 0)
        licz_odleglosci(bitmapa, odleglosci, odl_od_jedynki, i + mod1, j, mod1,
                        mod2);
    if (j + mod2 < m && j + mod2 >= 0)
        licz_odleglosci(bitmapa, odleglosci, odl_od_jedynki, i, j + mod2, mod1,
                        mod2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    string line;
    vector<int> bitmapa[n];
    vector<int> odleglosci[n];
    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (char digit : line) {
            odleglosci[i].push_back(182 * 182);
            bitmapa[i].push_back(digit - '0');
        }
    }

    licz_odleglosci(bitmapa, odleglosci, 182 * 182, 0, 0, 1, 1);
    licz_odleglosci(bitmapa, odleglosci, 182 * 182, n - 1, 0, -1, 1);
    licz_odleglosci(bitmapa, odleglosci, 182 * 182, 0, m - 1, 1, -1);
    licz_odleglosci(bitmapa, odleglosci, 182 * 182, n - 1, m - 1, -1, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << odleglosci[i][j] << ' ';
        }
        cout << "\n";
    }
}
