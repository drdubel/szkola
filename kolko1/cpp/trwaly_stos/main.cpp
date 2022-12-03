#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_polecen, liczba, usunieta;
    char operacja;
    vector<vector<int>> stosy;
    vector<int> stos;
    cin >> il_polecen;
    for (int i = 0; i < il_polecen; i++) {
        cin >> operacja;
        stosy.push_back(stos);
        if (operacja == '+') {
            cin >> liczba;
            stos.push_back(liczba);
        } else if (operacja == '-') {
            usunieta = stos.back();
            stos.pop_back();
        } else if (operacja == '*') {
            cin >> liczba;
            stos = stosy[stosy.size() - liczba - 1];
        }
        if (stos.size() > 0) {
            cout << stos[stos.size() - 1] << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
