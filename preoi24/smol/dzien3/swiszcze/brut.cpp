#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 5e5 + 7;
pair<int, int> swiszcze[MAXN];
int n;

int ile_grup(int najmlodszy = 2e9, int i = 0, int il_grup = 0) {
    if (i == n) return il_grup;

    int il_grup1 = 2e9;

    if (swiszcze[i].first >= najmlodszy)
        il_grup1 = ile_grup(najmlodszy, i + 1, il_grup);

    il_grup = min(
        ile_grup(swiszcze[i].first / swiszcze[i].second, i + 1, il_grup + 1),
        il_grup1);

    return il_grup;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> swiszcze[i].first >> swiszcze[i].second;
    }

    sort(swiszcze, swiszcze + n, greater<pair<int, int>>());

    int il_grup = ile_grup();

    cout << il_grup << '\n';
}