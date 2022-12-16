#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il_talerzy, il_polecen, liczba, usunieta, i, x = 0;
    string operacja;
    vector<int> kolejnosc;
    cin >> il_talerzy >> il_polecen;
    int talerze[il_talerzy];
    for (int &talerz : talerze) {
        talerz = -1;
    }
    for (i = 0; i < il_polecen; i++) {
        cin >> operacja;
        if (operacja == "odloz") {
            cin >> liczba;
            talerze[liczba - 1] = x + 1;
            kolejnosc.push_back(liczba - 1);
            x++;
        } else if (operacja == "pytaj") {
            cin >> liczba;
            if (talerze[liczba - 1] == -1) {
                cout << "-1\n";
            } else {
                cout << x - talerze[liczba - 1] << "\n";
            }
        } else if (operacja == "zdejmij") {
            talerze[kolejnosc.back()] = -1;
            kolejnosc.pop_back();
            x--;
        }
    }
}
