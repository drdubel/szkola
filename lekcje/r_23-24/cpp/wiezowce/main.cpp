#include "wie.h"

using namespace std;

const long long MAXN = 1e18 + 7;
long long najw = 1, sro, l, r;
int n;

void binsearch(int i) {
    l = najw;
    r = MAXN;
    while (l + 1 < r) {
        sro = l + (r - l) / 2 + (r - l) % 2;
        if (zamowienie(i, sro)) {
            l = sro;
        } else {
            r = sro;
        }
    }
    if (l == 1e18 - 1) {
        if (zamowienie(i, 1e18)) najw = 1e18;
        return;
    }
    najw = max(l, najw);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    n = wezN();
    vector<int> kolejnosc(n);
    for (int i = 0; i < n; ++i) kolejnosc[i] = i + 1;
    random_shuffle(kolejnosc.begin(), kolejnosc.end());
    for (int i : kolejnosc) {
        if (zamowienie(i, najw + 1)) {
            binsearch(i);
        }
        if (najw == MAXN) {
            break;
        }
    }
    odpowiedz(najw);
}