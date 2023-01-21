#include <iostream>

using namespace std;

const int MAXN = 1007;
int il_krawedzi, il_wierzcholkow, il_zapytan, krawedz1, krawedz2, i;
bool graf[MAXN][MAXN];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_wierzcholkow >> il_krawedzi;
    for (i = 0; i < il_krawedzi; ++i) {
        cin >> krawedz1 >> krawedz2;
        graf[krawedz1][krawedz2] = true;
        graf[krawedz2][krawedz1] = true;
    }
    cin >> il_zapytan;
    for (i = 0; i < il_zapytan; ++i) {
        cin >> krawedz1 >> krawedz2;
        if (graf[krawedz1][krawedz2]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
}