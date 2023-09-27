#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int MOD = 1e9 + 7;
    int n, x;
    cin >> n;
    long long dp[n + 1];
    dp[0] = 1;
    map<int, int> pop;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        dp[i] = (2 * dp[i - 1] -
                 (pop.find(x) != pop.end() ? dp[pop[x] - 1] : 0) + MOD) %
                MOD;
        pop[x] = i;
    }
    cout << dp[n];
}