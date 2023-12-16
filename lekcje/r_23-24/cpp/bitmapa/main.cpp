#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> licz_odleglosci(vector<vector<int>> bitmapa,
                                    vector<vector<int>> odleglosci, int n,
                                    int m) {
    int akt_odl;

    for (int i = 0; i < n; ++i) {
        akt_odl = 182 * 182;
        for (int j = 0; j < m; ++j) {
            if (bitmapa[i][j] == 1) {
                odleglosci[i][j] = 0;
                akt_odl = 1;
                continue;
            }

            akt_odl = min(akt_odl, odleglosci[i][j]);
            odleglosci[i][j] = akt_odl;

            ++akt_odl;
        }
    }

    for (int i = 0; i < n; ++i) {
        akt_odl = 182 * 182;
        for (int j = m - 1; j >= 0; --j) {
            if (bitmapa[i][j] == 1) {
                odleglosci[i][j] = 0;
                akt_odl = 1;
                continue;
            }

            akt_odl = min(akt_odl, odleglosci[i][j]);
            odleglosci[i][j] = akt_odl;

            ++akt_odl;
        }
    }

    for (int j = 0; j < m; ++j) {
        akt_odl = 182 * 182;
        for (int i = 0; i < n; ++i) {
            if (bitmapa[i][j] == 1) {
                odleglosci[i][j] = 0;
                akt_odl = 1;
                continue;
            }

            akt_odl = min(akt_odl, odleglosci[i][j]);
            odleglosci[i][j] = akt_odl;

            ++akt_odl;
        }
    }

    for (int j = 0; j < m; ++j) {
        akt_odl = 182 * 182;
        for (int i = n - 1; i >= 0; --i) {
            if (bitmapa[i][j] == 1) {
                odleglosci[i][j] = 0;
                akt_odl = 1;
                continue;
            }

            akt_odl = min(akt_odl, odleglosci[i][j]);
            odleglosci[i][j] = akt_odl;

            ++akt_odl;
        }
    }

    return odleglosci;
}

int main() {
    int n, m;
    cin >> n >> m;
    string line;
    vector<vector<int>> bitmapa(n, vector<int>(m, 0));
    vector<vector<int>> odleglosci(n, vector<int>(m, 182 * 182));

    for (int i = 0; i < n; ++i) {
        cin >> line;
        for (int j = 0; j < m; ++j) {
            bitmapa[i][j] = (int)(line[j] - '0');
        }
    }

    odleglosci = licz_odleglosci(bitmapa, odleglosci, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << odleglosci[i][j] << ' ';
        }
        cout << "\n";
    }
}
