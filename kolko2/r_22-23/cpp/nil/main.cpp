#include <iostream>
#include <vector>
using namespace std;
constexpr int maxn = 1e6 + 7;
vector<int> macierz[maxn];
int wart[maxn];
bool odw[maxn]{};
long long read(int v) {
    long long out = 0, out1 = 0;
    odw[v] = 1;
    for (auto wi : macierz[v]) {
        if (!odw[wi]) {
            out = wart[wi];
            out += read(wi);
        }
        out1 = max(out, out1);
    }
    return out1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> wart[i];
    }
    int a, b;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        macierz[a].push_back(b);
        macierz[b].push_back(a);
    }
    cout << read(1) + wart[1];
}