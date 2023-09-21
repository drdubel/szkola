#include "wie.h"

using namespace std;

const long long MAXN = 1e18;
long long najw = 1, sro, l, r;
int n;

void binsearch(int i) {
    l = najw;
    r = MAXN;
    while (l + 1 < r) {
        // cout << sro << ' ' << l << ' ' << r << "\n";
        sro = l + (r - l) / 2 + (r - l) % 2;
        if (zamowienie(i, sro)) {
            l = sro;
        } else {
            r = sro;
        }
    }
    // cout << sro << ' ' << l << ' ' << r << "\n";
    if (l == 1e18 - 1) {
        najw = 1e18;
        return;
    }
    najw = max(l, najw);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n = wezN();
    for (int i = 1; i <= n; ++i) {
        if (zamowienie(i, najw + 1)) {
            binsearch(i);
        }
        if (najw == MAXN) {
            break;
        }
    }
    odpowiedz(najw);
}