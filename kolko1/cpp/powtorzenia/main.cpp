#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int liczba, il_liczb, i;
    unordered_map<int, int> ilosci_liczb;
    scanf("%d", &il_liczb);
    for (i = 0; i < il_liczb; i++) {
        scanf("%d", &liczba);
        if (ilosci_liczb.find(liczba) == ilosci_liczb.end()) {
            ilosci_liczb.insert(pair<int, int>(liczba, 1));
        } else {
            ilosci_liczb[liczba]++;
        }
    }
    for (auto liczba : ilosci_liczb) {
        if (liczba.first != liczba.second) {
            cout << "NIE\n";
            return 0;
        }
    }
    cout << "TAK\n";
}
