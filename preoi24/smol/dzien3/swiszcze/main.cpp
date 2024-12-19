#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 5e5 + 7;
pair<int, int> swiszcze[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, il_grup = 0;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> swiszcze[i].first >> swiszcze[i].second;
    }

    sort(swiszcze, swiszcze + n, greater<pair<int, int>>());

    double najmlodszy = 1e9 + 7;

    for (int i = 0; i < n; ++i) {
        if (najmlodszy > (double)swiszcze[i].first) {
            najmlodszy = swiszcze[i].first / swiszcze[i].second;
            il_grup++;
        }
    }

    cout << il_grup << '\n';
}