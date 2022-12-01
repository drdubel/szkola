#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long wysokosc, szerokosc, wartosc, i, j;
    cin >> wysokosc >> szerokosc;
    long long sumy_rzedow[wysokosc];
    long long sumy_kolumn[szerokosc];
    for (i = 0; i < wysokosc; i++) {
        sumy_rzedow[i] = 0;
        for (j = 0; j < szerokosc; j++) {
            if (i == 0) {
                sumy_kolumn[j] = 0;
            }
            cin >> wartosc;
            sumy_rzedow[i] += wartosc;
            sumy_kolumn[j] += wartosc;
        }
    }
    for (auto suma_rzedu : sumy_rzedow) {
        cout << suma_rzedu << ' ';
    }
    cout << "\n";
    for (auto suma_kolumny : sumy_kolumn) {
        cout << suma_kolumny << ' ';
    }
    cout << "\n";
}
