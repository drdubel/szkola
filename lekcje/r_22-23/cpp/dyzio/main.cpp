#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 1e6;

int main() {
    int il_zestawow_danych, poczatek, koniec, i, j;
    bool liczby[MAXN];
    cin >> il_zestawow_danych;
    for (i = 2; i <= MAXN + 1; i++) {
        liczby[i] = true;
    }
    int max_dzielnik = sqrt(MAXN);
    for (i = 2; i <= max_dzielnik; i++) {
        if (liczby[i]) {
            for (j = i * i; j <= MAXN; j += i) {
                liczby[j] = false;
            }
        }
    }
    int suma_prefiksowa[MAXN + 1];
    suma_prefiksowa[0] = 0;
    for (i = 1; i <= MAXN; i++) {
        suma_prefiksowa[i] = suma_prefiksowa[i - 1];
        if (liczby[i]) {
            suma_prefiksowa[i]++;
        }
    }
    for (j = 0; j < il_zestawow_danych; j++) {
        cin >> poczatek >> koniec;
        cout << suma_prefiksowa[koniec] - suma_prefiksowa[poczatek - 1] << "\n";
    }
}