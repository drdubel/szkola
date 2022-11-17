#include <iostream>
#include <string>
using namespace std;


int szyfruj(int o_ile, string wiadomosc) {
    string zaszyfrowana_wiadomosc = "";
    zaszyfrowana_wiadomosc += "a";
    return zaszyfrowana_wiadomosc;
}


int main() {
    string co_robic;
    int o_ile;
    string wiadomosc;
    cin >> co_robic >> o_ile >> ws;
    getline(cin, wiadomosc);
    if (co_robic == "szyfruj") {
        cout << szyfruj(o_ile, wiadomosc);
    }
}