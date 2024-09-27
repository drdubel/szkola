#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, reszki = 0, orly = 0, najdluzszy_ciag = 0;
    string rzuty;

    cin >> n >> k;
    cin >> rzuty;

    for (int i = 0; i < n; i++) {
        reszki = 0;
        orly = 0;

        for (int j = i; j < n; j++) {
            if (rzuty[j] == 'R') {
                reszki++;
            } else {
                orly++;
            }

            if (orly == k * reszki) {
                najdluzszy_ciag = max(najdluzszy_ciag, reszki);
            }
        }
    }

    cout << najdluzszy_ciag * (1 + k) << "\n";
}