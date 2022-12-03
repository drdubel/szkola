#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_polecen, liczba, usunieta;
    char operacja;
    vector<int> stos;
    cin >> il_polecen;
    for (int i = 0; i < il_polecen; i++) {
        cin >> operacja;
        if (operacja == '+') {
            cin >> liczba;
            stos.push_back(liczba);
        } else if (operacja == '-') {
            usunieta = stos.back();
            stos.pop_back();
            cout << usunieta << "\n";
        }
    }
}
