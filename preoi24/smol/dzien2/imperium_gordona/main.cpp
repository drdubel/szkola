#include <iostream>

using namespace std;

constexpr int MAXN = 2e5 + 7;
int krulestwa[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, a, b, stolica = 0, koszt_podboju = 0;
        cin >> n >> a >> b;

        for (int j = 0; j < n; ++j) {
            cin >> krulestwa[j];
        }

        for (int j = 0; j < n; ++j) {
            koszt_podboju += b * (krulestwa[j] - stolica);

            if (a < b * (n - j - 1)) {
                koszt_podboju += a * (krulestwa[j] - stolica);
                stolica = krulestwa[j];
            }
        }

        cout << koszt_podboju << "\n";
    }
}