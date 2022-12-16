#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il_talerzy, il_polecen, liczba, usunieta, dl_stosu = 0, i;
    vector<int>::iterator it, poczatek, koniec;
    string operacja;
    vector<int> stos;
    cin >> il_talerzy >> il_polecen;
    for (i = 0; i < il_polecen; i++) {
        cin >> operacja;
        if (operacja == "odloz") {
            cin >> liczba;
            dl_stosu++;
            stos.push_back(liczba);
        } else if (operacja == "pytaj") {
            cin >> liczba;
            poczatek = stos.begin();
            koniec = stos.end();
            it = find(poczatek, koniec, liczba);
            if (it != koniec) {
                cout << dl_stosu - (it - poczatek + 1) << "\n";
            } else {
                cout << "-1\n";
            }
        } else if (operacja == "zdejmij") {
            dl_stosu--;
            stos.pop_back();
        }
    }
}
