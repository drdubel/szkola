#include <iostream>

using namespace std;


long long szybkie_potegowanie(long long liczba, long long wykladnik) {
    if (wykladnik == 0) {
        return 1;
    }
    if (wykladnik%2 == 0) {
        long long wynik = szybkie_potegowanie(liczba, wykladnik / 2);
        return (wynik * wynik) % 1000000007;
    }
    else {
        long long wynik = szybkie_potegowanie(liczba, wykladnik - 1);
        return (wynik * liczba) % 1000000007;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long il_poteg, liczba, wykladnik;
    cin >> il_poteg;
    for (long long i = 0; i < il_poteg; i++) {
        cin >> liczba >> wykladnik;
        cout << szybkie_potegowanie(liczba, wykladnik) << "\n";
    }
}