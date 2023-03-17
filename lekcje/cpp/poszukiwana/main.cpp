#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
int liczby[MAXN], n, q, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> liczby[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> k;
        if (k > liczby[n - 1]) {
            cout << "AAAAAAAAAAAAAAAAAA!11!!1!!\n";
            continue;
        }
        auto gk = lower_bound(liczby, liczby + n, k);
        cout << *gk << "\n";
    }
}