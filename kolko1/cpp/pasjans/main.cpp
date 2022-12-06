#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_kart, karta, operacja, i, j;
    vector<int> stosy;
    string wyjscie = "\n";
    cin >> il_kart;
    for (i = 0; i < il_kart; i++) {
        cin >> karta;
        operacja = 1;
        j = 0;
        for (int &stos : stosy) {
            j++;
            if (stos > karta) {
                stos = karta;
                operacja = 2;
                wyjscie += "2 " + to_string(j) + "\n";
                break;
            }
        }
        if (operacja == 1) {
            stosy.push_back(karta);
            wyjscie += "1\n";
        }
    }
    cout << stosy.size() << wyjscie;
}
