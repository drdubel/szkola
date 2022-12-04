#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_operacji, kwota, i;
    string pesel;
    map<string, int> konta;
    cin >> il_operacji;
    for (i = 0; i < il_operacji; i++) {
        cin >> pesel >> kwota;
        if (kwota < 0) {
            if (konta.find(pesel) != konta.end()) {
                if (konta[pesel] + kwota >= 0) {
                    konta[pesel] += kwota;
                    cout << konta[pesel] << "\n";
                } else {
                    cout << "NIE\n";
                }
            } else {
                cout << "NIE\n";
            }
        } else {
            if (konta.find(pesel) == konta.end()) {
                konta.insert(pair<string, int>(pesel, kwota));
            } else {
                konta[pesel] += kwota;
            }
            cout << konta[pesel] << "\n";
        }
    }
}
