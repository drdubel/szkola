#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int min(vector<int> lista, int odkad) {
    int najw_element = pow(10, 9) + 1;
    int akt_element;
    for (int i=odkad; i < lista.size(); i++) {
        akt_element = lista[i];
        if (akt_element < najw_element) {
            najw_element = akt_element;
        }
    }
    return najw_element;
}


int find(vector<int> lista, int szukany_element) {
    int akt_element;
    int i = lista.size();
    while (akt_element != szukany_element) {
        i--;
        akt_element = lista[i];
    }
    return i;
}


int main() {
    int il_osob;
    int pozycja = 0;
    int wydatki = 0;
    int odkad = 0;
    cin >> il_osob;
    vector<int> ceny_przekupstwa(il_osob);
    for (auto &x:ceny_przekupstwa) {
        cin >> x;
    }
    while (pozycja < il_osob) {
        int najtansze_przekupstwo = min(ceny_przekupstwa, odkad);
        int najtansze_miejsce = find(ceny_przekupstwa, najtansze_przekupstwo) + 1;
        wydatki += (najtansze_miejsce - pozycja) * najtansze_przekupstwo;
        pozycja += najtansze_miejsce;
        odkad += najtansze_miejsce;
    }
    cout << wydatki << "\n";
}