#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long il_polecen, liczba;
    char operacja;
    set<long long> zbior;
    cin >> il_polecen;
    for (long long i = 0; i < il_polecen; i++) {
        cin >> operacja;
        if (operacja == '+') {
            cin >> liczba;
            zbior.insert(liczba);
        } else if (operacja == '-') {
            cin >> liczba;
            zbior.erase(liczba);
        } else if (operacja == 'f') {
            cin >> liczba;
            auto wieksza = zbior.upper_bound(liczba);
            if (*wieksza) {
                cout << *wieksza << "\n";
            } else {
                cout << "BRAK\n";
            }
        } else if (operacja == 's') {
            cout << zbior.size() << "\n";
        } else if (operacja == 'w') {
            for (auto element : zbior) {
                cout << element << ' ';
            }
            cout << "\n";
        }
    }
}
