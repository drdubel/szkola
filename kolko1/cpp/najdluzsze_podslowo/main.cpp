#include <iostream>

using namespace std;

int main() {
    string slowo;
    cin >> slowo;
    int najdluzsze_podslowo = 0, dl_akt_podslowa = 0;
    for (int i = 0; i < slowo.size(); i++) {
        if (slowo[i] == 'a') {
            dl_akt_podslowa++;
            if (dl_akt_podslowa > najdluzsze_podslowo) {
                najdluzsze_podslowo = dl_akt_podslowa;
            }
        } else {
            dl_akt_podslowa = 0;
        }
    }
    if (najdluzsze_podslowo) {
        cout << string(najdluzsze_podslowo, 'a');
    } else {
        cout << "BRAK";
    }
}