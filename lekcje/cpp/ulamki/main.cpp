#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long il_ulamkow, licznik1, licznik2, mianownik1, mianownik2,
        suma_licznikow, wspolny_mianownik, nwd, nww;
    cin >> il_ulamkow;
    for (int i = 0; i < il_ulamkow; i++) {
        cin >> licznik1 >> mianownik1 >> licznik2 >> mianownik2;
        nwd = __gcd(mianownik1, mianownik2);
        nww = mianownik1 * mianownik2 / nwd;
        suma_licznikow =
            licznik1 * (mianownik2 / nwd) + licznik2 * (mianownik1 / nwd);
        wspolny_mianownik = nww;
        nwd = __gcd(suma_licznikow, wspolny_mianownik);
        cout << suma_licznikow / nwd << ' ' << wspolny_mianownik / nwd << "\n";
    }
}