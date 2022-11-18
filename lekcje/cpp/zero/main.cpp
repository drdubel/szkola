#include <iostream>
using namespace std;


int main() {
    int il_liczb, ulubione_liczby = 0, i;
    string liczba;
    cin >> il_liczb;
    for (i = 0; i < il_liczb; i++) {
        cin >> liczba;
        if ((liczba.size() > 1) & (liczba[liczba.size() - 2] == '0')) {
            ulubione_liczby++;
        }
    }
    cout << ulubione_liczby << "\n";
}