#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
int il_par, i;
double waga1, waga2;
pair<int, int> pary[MAXN];

bool porownaj(pair<int, int> para1, pair<int, int> para2) {
    waga1 = para1.first / pow(2, para1.second);
    waga2 = para2.first / pow(2, para2.second);
    if (waga1 == waga2) {
        return para1.first < para2.first;
    }
    return waga1 < waga2;
}

int main() {
    cin >> il_par;
    for (i = 0; i < il_par; ++i) {
        cin >> pary[i].first >> pary[i].second;
    }
    sort(pary, pary + il_par, porownaj);
    for (i = 0; i < il_par; ++i) {
        cout << pary[i].first << ' ' << pary[i].second << "\n";
    }
}