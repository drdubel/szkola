#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 1e3 + 7;
int plansza[MAXN][MAXN], dp[MAXN][MAXN], n;
long long il_drog = 0;

void count_paths() {
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (plansza[i][j] == 1) continue;
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 1000000;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> plansza[i][j];
        }
    }
    count_paths();
    cout << dp[n][n];
}