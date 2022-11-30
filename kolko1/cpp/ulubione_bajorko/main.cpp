#include <iostream>

using namespace std;

long long nwd(unsigned long long liczba1, unsigned long long liczba2) {
    while (liczba2 != 0) {
        swap(liczba1, liczba2);
        liczba2 = liczba2 % liczba1;
    }
    return liczba1;
}

long long nww(unsigned long long liczba1, unsigned long long liczba2) {
    return (liczba1 * liczba2) / nwd(liczba1, liczba2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long czestotliwosc_kaczki_1, czestotliwosc_kaczki_2;
    cin >> czestotliwosc_kaczki_1 >> czestotliwosc_kaczki_2;
    cout << nww(czestotliwosc_kaczki_1, czestotliwosc_kaczki_2);
}