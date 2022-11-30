#include <iostream>

using namespace std;

void sito_erastotenesa(int do_ilu) {
    bool czy_pierwsza[do_ilu + 1];
    for (int number = 2; number * number <= do_ilu; number++) {
        if (czy_pierwsza[number] == false) {
            cout << number << "\n";
            for (int i = number * number; i <= do_ilu; i += number)
                czy_pierwsza[i] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long liczba;
    cin >> liczba;
    sito_erastotenesa(liczba);
}
