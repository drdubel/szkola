#include <algorithm>
#include <iostream>
using namespace std;

long long il_schronisk, il_dni, mid, wynik, res, suma;
int odleglosci[1000007];

bool czy_dziala(long long x) {
    suma = 0;
    wynik = 0;
    for (int i = 1; i < il_schronisk; i++) {
        if (odleglosci[i] > x) {
            return false;
        }
        if (suma + odleglosci[i] > x) {
            suma = odleglosci[i];
            wynik++;
        } else {
            suma += odleglosci[i];
        }
    }
    if (suma > 0) wynik++;
    return (wynik <= il_dni);
}

long long wyszukiwanie_binarne(long long l, long long r) {
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (czy_dziala(mid)) {
            r = mid;
            res = mid;
        } else
            l = mid;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> il_schronisk >> il_dni;
    for (int i = 1; i < il_schronisk; i++) cin >> odleglosci[i];
    cout << wyszukiwanie_binarne(1, 1e18);

    return 0;
}