#include <iostream>
#include <set>

using namespace std;

constexpr int MAXN = 1e6 + 7;
multiset<pair<long long, long long>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k, a, cnt = 0;
    string ans;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a;

        s.insert({a, i});
    }

    while (!s.empty()) {
        long long minn = s.begin()->first;
        long long x1 = s.begin()->second;
        long long maxx = s.rbegin()->first;
        long long x2 = s.rbegin()->second;
        long long summ = minn + maxx;

        if (minn == k) {
            ++cnt;

            ans += "1 " + to_string(x1) + " " + to_string(minn) + "\n";
            s.erase({minn, x1});

            continue;
        }

        if (maxx == k) {
            ++cnt;

            ans += "1 " + to_string(x2) + " " + to_string(maxx) + "\n";
            s.erase({maxx, x2});

            continue;
        }

        if (x1 == x2) {
            ++cnt;

            if (minn <= k)
                ans += "1 " + to_string(x1) + " " + to_string(minn) + "\n";
            else {
                ans += "1 " + to_string(x1) + " " + to_string(k) + "\n";
                s.insert({minn - k, x1});
            }

            s.erase({minn, x1});

            continue;
        }

        if (summ > k) {
            ++cnt;

            s.erase({minn, x1});
            s.erase({maxx, x2});

            if (summ != k) s.insert({summ - k, x2});

            ans += "2 " + to_string(x1) + " " + to_string(minn) + " " +
                   to_string(x2) + " " + to_string(k - minn) + "\n";
        } else {
            ++cnt;

            s.erase({minn, x1});
            s.erase({maxx, x2});

            ans += "2 " + to_string(x1) + " " + to_string(minn) + " " +
                   to_string(x2) + " " + to_string(maxx) + "\n";
        }
    }

    if (cnt > n) {
        cout << "NIE\n";
    } else {
        cout << "TAK\n";
        cout << ans;
    }

    if (cnt < n) {
        for (int i = 0; i < n - cnt; ++i) cout << "0\n";
    }
}