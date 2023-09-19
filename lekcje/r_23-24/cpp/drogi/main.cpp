#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 1e3 + 7;
int plansza[MAXN][MAXN], n, x;
long long il_drog = 0;

void count_paths() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (plansza[i][j] == 0) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            plansza[i][j] = x ^ 1;
        }
    }
    count_paths();
    cout << il_drog;
}