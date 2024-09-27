#include <iostream>
#include <queue>

using namespace std;

constexpr int MAXN = 1e5 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, moc_sygnalu = 0, il_nadajnikow = 0;

    cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        nadajniki;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        nadajniki.push({a, b});
    }

    for (int i = 0; i < n; i++) {
        a = nadajniki.top().first;
        b = nadajniki.top().second;
        nadajniki.pop();
        il_nadajnikow++;

        moc_sygnalu = max(moc_sygnalu + b - il_nadajnikow, 0);
    }
}