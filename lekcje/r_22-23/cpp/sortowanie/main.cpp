#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_liczb, od_ilu, do_ilu;
    cin >> il_liczb >> od_ilu >> do_ilu;
    int liczby[il_liczb];
    for (auto &liczba : liczby) {
        cin >> liczba;
    }
    sort(liczby + od_ilu - 1, liczby + do_ilu);
    for (auto liczba : liczby) {
        cout << liczba << ' ';
    }
}