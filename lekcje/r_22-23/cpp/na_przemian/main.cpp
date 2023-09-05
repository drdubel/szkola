#include <iostream>
#include <vector>
using namespace std;

int main() {
    int il_kartek;
    int il_liczb;
    int liczba;
    cin >> il_kartek;
    for (int j = 0; j < il_kartek; j++) {
        cin >> il_liczb;
        vector<int> pozycje_nieparzyste;
        for (int i = -1; i < il_liczb - 1; i++) {
            cin >> liczba;
            if (i % 2 == 0) {
                cout << liczba << ' ';
            } else {
                pozycje_nieparzyste.push_back(liczba);
            }
        }
        for (int i = 0; i < pozycje_nieparzyste.size(); i++) {
            cout << pozycje_nieparzyste[i] << ' ';
        }
        cout << '\n';
    }
}