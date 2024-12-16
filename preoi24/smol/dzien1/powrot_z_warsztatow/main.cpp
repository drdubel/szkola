#include <algorithm>
#include <iostream>

using namespace std;

constexpr unsigned int MAXN = 2e5 + 7;

int rodzic[MAXN], rozmiar[MAXN];
pair<int, int> x[MAXN], y[MAXN];
string operacja;

int find(int v) {
    if (v == rodzic[v]) return v;
    return rodzic[v] = find(rodzic[v]);
}

void unionn(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rozmiar[a] < rozmiar[b]) swap(a, b);
        rodzic[b] = a;
        rozmiar[a] += rozmiar[b];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, a, b;

    cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> y[i].first;

        x[i].second = i + 1;
        y[i].second = i + 1;

        rodzic[i + 1] = i + 1;
        rozmiar[i + 1] = 1;
    }

    sort(x, x + n);
    sort(y, y + n);

    pair<int, int> pop_x = {2e9, -1};
    pair<int, int> pop_y = {2e9, -1};

    for (int i = 0; i < n; ++i) {
        if (x[i].first == pop_x.first) {
            unionn(x[i].second, pop_x.second);
        }
        if (y[i].first == pop_y.first) {
            unionn(y[i].second, pop_y.second);
        }

        pop_x = x[i];
        pop_y = y[i];
    }

    for (int i = 0; i < t; ++i) {
        cin >> a >> b;

        if (find(a) == find(b))
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}