#include <iostream>
#include <vector>

using namespace std;

int il_stolikow = 0, il_gosci, gosc, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_gosci;
    vector<int> rozmieszczenie(il_gosci + 1);
    vector<bool> czy_odwiedzeni(il_gosci + 1, false);
    for (i = 0; i < il_gosci; ++i) {
        cin >> rozmieszczenie[i + 1];
    }
    for (i = 1; i < il_gosci + 1; ++i) {
        if (!czy_odwiedzeni[i]) {
            il_stolikow++;
            gosc = rozmieszczenie[i];
            while (!czy_odwiedzeni[gosc]) {
                czy_odwiedzeni[gosc] = true;
                gosc = rozmieszczenie[gosc];
            }
        }
    }
    cout << il_stolikow << "\n";
}
