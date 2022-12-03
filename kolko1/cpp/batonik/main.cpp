#include <iostream>

using namespace std;

long long najwiekszy_podciag(int poziomy_smacznosci[], int dl_batonika) {
    long long minimalna_suma_prefiksu = 0;
    long long suma = -1000001;

    long long suma_prefiksu[dl_batonika];
    suma_prefiksu[0] = poziomy_smacznosci[0];
    for (int i = 1; i < dl_batonika; i++)
        suma_prefiksu[i] = suma_prefiksu[i - 1] + poziomy_smacznosci[i];

    for (int i = 0; i < dl_batonika; i++) {
        suma = max(suma, suma_prefiksu[i] - minimalna_suma_prefiksu);
        minimalna_suma_prefiksu =
            min(minimalna_suma_prefiksu, suma_prefiksu[i]);
    }

    return suma;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dl_batonika;
    cin >> dl_batonika;
    int poziomy_smacznosci[dl_batonika];
    for (int &poziom_smacznosci : poziomy_smacznosci) {
        cin >> poziom_smacznosci;
    }
    cout << najwiekszy_podciag(poziomy_smacznosci, dl_batonika) << "\n";
}
