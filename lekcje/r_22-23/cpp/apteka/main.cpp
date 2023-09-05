#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int pozycja = 0, cena, i;
long long il_osob, wydatki = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_osob;
    vector<pair<int, int>> ludzie = {{0, 0}};
    for (i = 1; i < il_osob + 1; ++i) {
        cin >> cena;
        ludzie.push_back({cena, i});
    }
    sort(ludzie.begin() + 1, ludzie.end());
    for (i = 1; i < il_osob + 1; ++i) {
        if (ludzie[i].second > pozycja) {
            wydatki +=
                (long long)(ludzie[i].second - pozycja) * ludzie[i].first;
            pozycja = ludzie[i].second;
        }
    }
    cout << wydatki << "\n";
}