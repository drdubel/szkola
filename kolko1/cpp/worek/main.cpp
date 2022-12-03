#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    long long numer_w_kuli, pytanie_o_kule;
    int il_zapytan, il_kul, i;
    unordered_map<long long, int> ilosci_numerow;
    scanf("%d", &il_kul);
    for (i = 0; i < il_kul; i++) {
        scanf("%lld", &numer_w_kuli);
        if (ilosci_numerow.find(numer_w_kuli) == ilosci_numerow.end()) {
            ilosci_numerow.insert(pair<long long, int>(numer_w_kuli, 1));
        } else {
            ilosci_numerow[numer_w_kuli]++;
        }
    }
    scanf("%d", &il_zapytan);
    for (i = 0; i < il_zapytan; i++) {
        scanf("%lld", &pytanie_o_kule);
        if (ilosci_numerow.find(pytanie_o_kule) == ilosci_numerow.end()) {
            printf("0\n");
        } else {
            printf("%d\n", ilosci_numerow[pytanie_o_kule]);
        }
    }
}
