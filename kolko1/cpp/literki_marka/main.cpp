#include <iostream>
#include <map>

using namespace std;

int litery[26];

int main() {
    string tekst;
    int wym_il_roznych_liter, il_roznych_liter = 0, koniec = 0,
                              koniec_i = 1e6 + 1, przod_i = -1;
    cin >> tekst >> wym_il_roznych_liter;
    for (int i = 0; i < tekst.size(); i++) {
        while (il_roznych_liter < wym_il_roznych_liter &&
               koniec < tekst.size()) {
            if (litery[(int)tekst[koniec] - 97] == 0) {
                il_roznych_liter++;
            }
            litery[(int)tekst[koniec] - 97]++;
            koniec++;
        }
        if (il_roznych_liter == wym_il_roznych_liter and
            (koniec_i - przod_i) > (koniec - i)) {
            koniec_i = koniec;
            przod_i = i;
        }
        litery[(int)tekst[i] - 97]--;
        if (litery[(int)tekst[i] - 97] == 0) {
            il_roznych_liter--;
        }
    }
    if (przod_i == -1) {
        cout << "BRAK";
    } else {
        cout << przod_i + 1 << ' ' << koniec_i;
    }
}