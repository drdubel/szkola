#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
long long h, n, m, c, prev_h, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> h;
        if (h >= m) {
            prev_h = i + 1;
        }
        c += prev_h;
    }
    cout << c;
}
