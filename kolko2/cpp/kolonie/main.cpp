#include <iostream>
using namespace std;

const int MAXN = 1e6 + 7;
int rodzic[MAXN], masa[MAXN], maks_iq[MAXN], min_iq[MAXN];
int il_bakterii, kolonia1, kolonia2, ktora_kolonia;
string operacja;

int Find(int kolonia1) {
    if (rodzic[kolonia1] == kolonia1) return kolonia1;
    rodzic[kolonia1] = Find(rodzic[kolonia1]);
    return (rodzic[kolonia1]);
}

void Union(int kolonia1, int kolonia2) {
    int ktora_kolonia, y;
    ktora_kolonia = Find(kolonia1);
    y = Find(kolonia2);
    if (ktora_kolonia == y) return;
    rodzic[ktora_kolonia] = rodzic[y];
    maks_iq[y] = max(maks_iq[y], maks_iq[ktora_kolonia]);
    min_iq[y] = min(min_iq[y], min_iq[ktora_kolonia]);
    masa[y] = masa[y] + masa[ktora_kolonia];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> il_bakterii;
    for (int i = 1; i <= il_bakterii; i++) {
        cin >> masa[i] >> min_iq[i];
        maks_iq[i] = min_iq[i];
        rodzic[i] = i;
    }

    while (cin >> operacja) {
        if (operacja == "JOIN") {
            cin >> kolonia1 >> kolonia2;
            Union(kolonia1, kolonia2);
        } else if (operacja[0] == 'I') {
            cin >> kolonia1;
            ktora_kolonia = Find(kolonia1);
            if (operacja == "IQ_MAX")
                cout << maks_iq[ktora_kolonia] << "\n";
            else
                cout << min_iq[ktora_kolonia] << "\n";
        } else {
            cin >> kolonia1;
            ktora_kolonia = Find(kolonia1);
            cout << masa[ktora_kolonia] << "\n";
        }
    }
}