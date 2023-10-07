#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Walka {
    long long atak, leczenie, bilans, id;
};

bool por(Walka a, Walka b) {
    if (a.atak != b.atak) return a.atak < b.atak;
    return a.leczenie > b.leczenie;
}
bool odw_por(Walka a, Walka b) {
    if (a.leczenie != b.leczenie) return a.leczenie > b.leczenie;
    return a.atak < b.atak;
}

vector<Walka> zwroc_kolejnosc(vector<Walka> dobre_walki,
                              vector<Walka> zle_walki, long long zycie, int n) {
    vector<Walka> walki_po_kolei = dobre_walki;
    walki_po_kolei.insert(walki_po_kolei.end(), zle_walki.begin(),
                          zle_walki.end());
    for (Walka walka : walki_po_kolei) {
        if (walka.atak >= zycie) {
            return vector<Walka>();
        }
        zycie += walka.bilans;
    }
    return walki_po_kolei;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, zycie;
    cin >> n >> zycie;
    Walka walki[n + 1], walka;
    vector<Walka> dobre_walki, zle_walki;
    for (int i = 1; i <= n; ++i) {
        Walka walka = walki[i];
        cin >> walka.atak >> walka.leczenie;
        walka.bilans = walka.leczenie - walka.atak;
        walka.id = i;
        if (walka.bilans > 0)
            dobre_walki.push_back(walka);
        else
            zle_walki.push_back(walka);
    }
    sort(dobre_walki.begin(), dobre_walki.end(), por);
    sort(zle_walki.begin(), zle_walki.end(), odw_por);
    vector<Walka> walki_po_kolei =
        zwroc_kolejnosc(dobre_walki, zle_walki, zycie, n);
    if (walki_po_kolei.size()) {
        cout << "TAK\n";
        for (Walka walka : walki_po_kolei) cout << walka.id << " ";
    } else {
        cout << "NIE";
    }
    cout << "\n";
}
