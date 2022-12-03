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
        switch (operacja) {
            case '+':
                cin >> liczba;
                zbior.insert(liczba);
                break;
            case '-':
                cin >> liczba;
                zbior.erase(liczba);
                break;
            case 'f':
                cin >> liczba;
                auto wieksza = zbior.upper_bound(liczba);
                if (*wieksza) {
                    cout << *wieksza << "\n";
                } else {
                    cout << "BRAK\n";
                }
                break;
            case 's':
                cout << zbior.size() << "\n";
                break;
            case 'w':
                for (auto element : zbior) {
                    cout << element << ' ';
                }
                cout << "\n";
                break;
        }
    }
}
