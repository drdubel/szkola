#include <algorithm>
#include <iostream>
using namespace std;

int il_access_pointow, il_klas;
int odleglosci[100000];

bool czy_dziala(int sala) {
    int access_pointy = il_access_pointow;
    int polozenie_access_pointu = -50000001;
    for (int i = 0; i < il_klas; i++) {
        if (odleglosci[i] - polozenie_access_pointu > sala) {
            access_pointy--;
            if (access_pointy < 0) {
                return false;
            }
            polozenie_access_pointu = odleglosci[i] + sala;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_access_pointow >> il_klas;
    for (int i = 0; i < il_klas; i++) {
        cin >> odleglosci[i];
        odleglosci[i] *= 100;
    }
    sort(odleglosci, odleglosci + il_klas);
    int pocz = 1;
    int kon = 50000000, mid;
    while (pocz < kon) {
        mid = (pocz + kon) / 2;
        if (czy_dziala(mid))
            kon = mid;
        else
            pocz = mid + 1;
    }
    cout << pocz / 100 << '.';
    if (pocz % 10 >= 5) {
        cout << pocz % 100 / 10 + 1;
        return 0;
    }
    cout << pocz % 100 / 10;
}