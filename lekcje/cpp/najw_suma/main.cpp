#include <iostream>
#include <vector>
using namespace std;


int main() {
    long long il_dni;
    cin >> il_dni;
    vector<long> zmiana_wys(il_dni);
    for (auto &x:zmiana_wys) {
        cin >> x;
    }
    long long maks_wys = -2147483647;
    long long dzien_maks_wys = 1;
    long long akt_wys = 0;
    for (int i=0; i < il_dni; i++) {
        akt_wys += zmiana_wys[i];
        if (akt_wys >= maks_wys) {
            maks_wys = akt_wys;
            dzien_maks_wys = i + 1;
        }
    }
    cout << dzien_maks_wys << "\n";
}
