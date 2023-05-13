#include <iostream>

using namespace std;

int main() {
    int res = -1e9, mini, n, a;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> mini;
    while (--n) {
        cin >> a;
        res = max(res, a - mini);
        mini = min(mini, a);
    }
    cout << res;
}
