#include <iostream>
using namespace std;

const unsigned int MAXN = 2e5 + 7;

int rodzic[MAXN], ranga[MAXN], il_wierzcholkow, il_krawedzi, il_zapytan, a, b,
    i;

int Find(int x) {
    if (rodzic[x] != x) rodzic[x] = Find(rodzic[x]);
    return rodzic[x];
}

void Union(int x, int y) {
    a = Find(x);
    b = Find(y);
    if (ranga[a] < ranga[b])
        rodzic[a] = b;
    else
        rodzic[b] = a;
    if (ranga[a] == ranga[b]) ++ranga[a];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_wierzcholkow >> il_krawedzi >> il_zapytan;
    for (int i = 1; i <= il_wierzcholkow; i++) rodzic[i] = i;

    for (i = 0; i < il_krawedzi; i++) {
        cin >> a >> b;
        Union(a, b);
    }
    for (i = 0; i < il_zapytan; i++) {
        cin >> a >> b;
        if (Find(a) == Find(b))
            cout << "T\n";
        else
            cout << "N\n";
    }
}
