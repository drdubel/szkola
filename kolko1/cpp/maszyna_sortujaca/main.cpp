#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_liczb, il_operacji, od_ilu, do_ilu;
    char operacja;
    cin >> il_liczb >> il_operacji;
    int liczby[il_liczb];
    for (auto &liczba : liczby) {
        cin >> liczba;
    }
    for (int i = 0; i < il_operacji; i++) {
        cin >> od_ilu >> do_ilu >> operacja;
        if (operacja == 'R') {
            sort(liczby + od_ilu - 1, liczby + do_ilu);
        } else if (operacja == 'M') {
            sort(liczby + od_ilu - 1, liczby + do_ilu, greater<int>());
        }
    }
    for (auto liczba : liczby) {
        cout << liczba << ' ';
    }
}