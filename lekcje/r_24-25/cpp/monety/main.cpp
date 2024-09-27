#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

constexpr int MAXN = 1e6 + 7;
long long rzuty_pref[MAXN];

long long najdluzszyCiag(long long n) {
    unordered_map<long long, long long> mp;

    long long max_dist = 0;
    for (long long i = 0; i < n + 1; i++) {
        if (mp.find(rzuty_pref[i]) == mp.end())
            mp[rzuty_pref[i]] = i;

        else
            max_dist = max(max_dist, i - mp[rzuty_pref[i]]);
    }

    return max_dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    string rzuty;

    cin >> n >> k;
    cin >> rzuty;

    for (long long i = 1; i < n + 1; i++) {
        rzuty_pref[i] = rzuty_pref[i - 1] + (rzuty[i - 1] == 'O' ? 1 : -k);
    }

    cout << najdluzszyCiag(n) << "\n";
}