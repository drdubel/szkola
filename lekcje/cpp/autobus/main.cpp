#include <iostream>

using namespace std;

int d, n, x, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> d;
    for (i = 0; i < d; i++) {
        cin >> n >> x;
        (x == n - 1) ? cout << n : cout << n - 1;
        cout << "\n";
    }
}