#include <algorithm>
#include <iostream>

using namespace std;

constexpr int MAXN = 5e5 + 7;
int komputery[MAXN], wyniki[MAXN], wynikiwtyl[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, wynik = 0, wynikwtyl = 0, opt_wynik = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> komputery[i];
        if (i < (n + 1) / 2) wynik += komputery[i];
        if (i >= n - (n + 1) / 2) wynikwtyl += komputery[i];
    }
    wyniki[0] = wynik;
    wynikiwtyl[n - 1] = wynikwtyl;

    for (int i = 1; i < n; i++) {
        wynik = komputery[(i + (n + 1) / 2 - 1) % n] - komputery[i - 1];
        wyniki[i] = wynik + wyniki[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        wynikwtyl = komputery[(n + 1 + i - (n + 1) / 2) % n] - komputery[i + 1];
        wynikiwtyl[i] = wynikwtyl + wynikiwtyl[i + 1];
    }

    for (int i = 0; i < n; i++) {
        opt_wynik = max(opt_wynik, min(wyniki[i], wynikiwtyl[i]));
    }

    cout << opt_wynik << "\n";
}