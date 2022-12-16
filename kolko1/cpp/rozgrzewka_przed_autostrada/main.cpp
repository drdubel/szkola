#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double il_odcinkow, wym_czas, maks_przekroczenie, akt_czas, dl_odcinka,
        ograniczenie, i;
    cin >> il_odcinkow >> wym_czas >> maks_przekroczenie;
    for (i = 0; i < il_odcinkow; i++) {
        cin >> dl_odcinka >> ograniczenie;
        akt_czas += dl_odcinka / (ograniczenie + maks_przekroczenie);
    }
    if (akt_czas >= wym_czas) {
        cout << "NIE";
    } else {
        cout << "TAK";
    }
}