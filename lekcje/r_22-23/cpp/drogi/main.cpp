#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 1e3 + 7;
int plansza[MAXN][MAXN], n;
long long il_drog = 1;

void count_paths(int i, int j) {
    if (i >= n || j >= n) {
        return;
    }
    cout << i << " " << j << "\n";
    if (plansza[i + 1][j] == 0 && plansza[i][j + 1] == 0) {
        il_drog += 1;
        count_paths(i + 1, j);
        count_paths(i, j + 1);
    } else if (plansza[i][j + 1] == 0) {
        count_paths(i, j + 1);
    } else if (plansza[i + 1][j] == 0) {
        count_paths(i + 1, j);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> plansza[i][j];
        }
    }
    count_paths(0, 0);
    cout << il_drog;
}