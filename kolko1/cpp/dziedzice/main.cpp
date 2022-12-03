#include <iostream>
#include <vector>

using namespace std;

long long gasienica(long long suma_fragmentow, vector<int> fragmenty,
                    int il_fragmentow) {
    long long suma = 0, wynik = 0;
    int glowa = 0, ogon;
    for (ogon = 0; ogon < il_fragmentow; ogon++) {
        while (glowa < il_fragmentow && suma < suma_fragmentow - suma) {
            suma += fragmenty[glowa];
            wynik = max(wynik, min(suma, suma_fragmentow - suma));
            glowa++;
        }
        suma -= fragmenty[ogon];
        wynik = max(wynik, min(suma, suma_fragmentow - suma));
    }
    return wynik;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il_fragmentow, i;
    cin >> il_fragmentow;
    long long suma_fragmentow = 0;
    vector<int> fragmenty(il_fragmentow);
    for (i = 0; i < il_fragmentow; i++) {
        cin >> fragmenty[i];
        suma_fragmentow += fragmenty[i];
    }
    cout << gasienica(suma_fragmentow, fragmenty, il_fragmentow) << "\n";
}