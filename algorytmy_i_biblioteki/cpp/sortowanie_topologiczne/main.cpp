#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 7;
int il_wierzcholkow, il_zaleznosci, skad, dokad;
vector<int> graf[MAXN];
int ile_odnog[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_wierzcholkow >> il_zaleznosci;
    for (int i = 0; i < il_zaleznosci; i++) {
        cin >> skad >> dokad;
        graf[skad].push_back(dokad);
    }
    vector<int> pierwsze;
    for (int i = 1; i <= il_wierzcholkow; i++)
        if (ile_odnog[i] == 0) pierwsze.push_back(i);

    if (pierwsze.size() != 1) {
        cout << "NIE";
        return 0;
    }
    vector<int> kolejnosc;
    while (!pierwsze.empty()) {
        int skad = pierwsze.back();
        pierwsze.pop_back();
        kolejnosc.push_back(skad);
        for (auto dokad : graf[skad]) {
            ile_odnog[dokad]--;
            if (ile_odnog[dokad] == 0) pierwsze.push_back(dokad);
        }
    }
    for (auto i : kolejnosc) cout << i << " ";
}
