#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_schronisk, il_dni;
    cin >> il_schronisk >> il_dni;
    int odleglosci[il_schronisk - 1];
    for (int &odleglosc : odleglosci) {
        cin >> odleglosc;
    }
}
