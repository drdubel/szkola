#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dl_danych;

int nwd(vector<int>& liczby, int ktora_liczba) {
    if (ktora_liczba == dl_danych - 1) {
        return liczby[ktora_liczba];
    }
    int liczba1 = liczby[ktora_liczba];
    int liczba2 = nwd(liczby, ktora_liczba + 1);
    return __gcd(liczba1, liczba2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> dl_danych;
    vector<int> liczby;
    int liczba;
    for (int i = 0; i < dl_danych; i++) {
        cin >> liczba;
        liczby.push_back(liczba);
    }
    cout << nwd(liczby, 0) << "\n";
}