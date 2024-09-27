#include <iostream>

using namespace std;

constexpr int MAXN = 2e5 + 7;
int gory[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, szczyty = 1, maxSzczyty = 0;
    bool rosn = true;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> gory[i];
    }

    for (int i = 1; i < n; i++) {
        if (rosn) {
            if (gory[i] > gory[i - 1]) {
                szczyty++;
            } else if (gory[i] < gory[i - 1]) {
                rosn = false;
                szczyty++;
            } else {
                maxSzczyty = max(maxSzczyty, szczyty);
                szczyty = 1;
            }
        } else {
            if (gory[i] < gory[i - 1]) {
                szczyty++;
            } else if (gory[i] > gory[i - 1]) {
                rosn = true;
                maxSzczyty = max(maxSzczyty, szczyty);
                szczyty = 2;
            } else {
                maxSzczyty = max(maxSzczyty, szczyty);
                szczyty = 1;
            }
        }
    }

    cout << max(maxSzczyty, szczyty) << "\n";
}
