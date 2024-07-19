#include <iostream>

using namespace std;

struct Gablota {
    long long d, p, r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, il_przestawien = 0;
    cin >> n;

    Gablota gabloty[n];

    for (int i = 0; i < n; i++) {
        cin >> gabloty[i].d >> gabloty[i].p >> gabloty[i].r;
    }

    for (int i = 0; i < n; i++) {
        il_przestawien += gabloty[i].d + gabloty[i].p + gabloty[i].r;
        il_przestawien -= max(gabloty[i].d, max(gabloty[i].p, gabloty[i].r));
    }

    cout << il_przestawien << "\n";
}