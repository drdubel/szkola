#include <algorithm>
#include <iostream>

using namespace std;

constexpr short maxn = 20007;
short in[maxn]{};
short k, n;

bool czydasie(short nn) {
    if (nn > n) return 0;
    short i;
    if (nn == 1) return 1;
    int c = max(in[1] - in[0], 0);
    for (i = 2; i < nn; ++i) {
        c += max(in[i] - in[i - 1], 0);
    }
    if (c <= k) return 1;
    short ogon = 1, glowa;
    for (glowa = nn; glowa < n; ++glowa) {
        c -= max(in[ogon] - in[ogon - 1], 0);
        c += max(in[glowa] - in[glowa - 1], 0);
        if (c <= k) return 1;
        ++ogon;
    }
    return 0;
}

int main() {
    short i;
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> in[i];
    }
    short b = 0, e = n + 1, m;
    while (b < e) {
        m = (b + e) / 2;
        if (czydasie(m))
            b = m + 1;
        else
            e = m;
    }
    short out = b - 1;
    reverse(in, in + n);
    b = 0, e = n + 1;
    while (b < e) {
        m = (b + e) / 2;
        if (czydasie(m))
            b = m + 1;
        else
            e = m;
    }
    out = max((short)out, (short)(b - 1));
    cout << out;
}