#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il_talerzy, il_polecen, liczba, usunieta, i;
    string operacja;
    vector<int> stos;
    cin >> il_talerzy >> il_polecen;
    for (i = 0; i < il_polecen; i++) {
        cin >> operacja;
        if (operacja == "odloz") {
            cin >> liczba;
            stos.push_back(liczba);
        } else if (operacja == "pytaj") {
            cin >> liczba;
            auto it = find(stos.begin(), stos.end(), liczba);
            if (it != stos.end()) {
                cout << stos.size() - (it - stos.begin() + 1) << "\n";
            } else {
                cout << "-1\n";
            }
        } else if (operacja == "zdejmij") {
            stos.pop_back();
        }
    }
}
