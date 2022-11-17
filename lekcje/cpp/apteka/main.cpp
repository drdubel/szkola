#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    int il_osob;
    int pozycja = 0;
    int wydatki = 0;
    int i = il_osob - 1;
    cin >> il_osob;
    vector<int> ceny_przekupstwa(il_osob);
    for (auto &x:ceny_przekupstwa) {
        cin >> x;
    }
    int ostatnia_osoba = ceny_przekupstwa[i];
    while (pozycja < il_osob) {
        i--;
        if (i < 0 || pozycja > ) {
            cout << (il_osob - pozycja) * ostatnia_osoba + wydatki << "\n";
            break
        }
        if (ceny_przekupstwa[i] < ostatnia_osoba) {
            wydatki += 
            pozycja
        }
    }
    cout << wydatki << "\n";
}