#include "wie.h"

using namespace std;

const long long MAXN = 1e18 + 7;
long long najw = 1, najwi = 1, sro;
int n;

void binsearch(int i) {
    long long l = najw, r = MAXN;
    while (l < r) {
        sro = (l + r) / 2;
        if (zamowienie(i, sro)) {
            l = sro + 1;
        } else {
            r = sro;
        }
    }
    if (l > najw) {
        if (zamowienie(i, 1e18)) {
            odpowiedz(1e18);
        }
        najw = l - 1;
        najwi = i;
    }
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