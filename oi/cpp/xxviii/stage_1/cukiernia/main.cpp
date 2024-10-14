#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long il_przestawien = 0;
    cin >> n;

    int drozdzowki[n], paczki[n], rogaliki[n],
        najw_drozdzowka = 0, najw_paczek = 0, najw_rogalik = 0;
    pair<int, int> pos_drozdzowki[n], pos_paczki[n], pos_rogaliki[n];
    deque<int> posortowane[3];

    for (int i = 0; i < n; i++) {
        cin >> drozdzowki[i] >> paczki[i] >> rogaliki[i];
        pos_drozdzowki[i] = {drozdzowki[i], i};
        pos_paczki[i] = {paczki[i], i};
        pos_rogaliki[i] = {rogaliki[i], i};

        il_przestawien += drozdzowki[i] + paczki[i] + rogaliki[i];
        il_przestawien -= max({drozdzowki[i], paczki[i], rogaliki[i]});
    }

    sort(pos_drozdzowki, pos_drozdzowki + n, greater<pair<int, int>>());
    sort(pos_paczki, pos_paczki + n, greater<pair<int, int>>());
    sort(pos_rogaliki, pos_rogaliki + n, greater<pair<int, int>>());

    for (int i = 0; i < min(300, n); i++) {
        posortowane[0].push_back(pos_drozdzowki[i].second);
        posortowane[1].push_back(pos_paczki[i].second);
        posortowane[2].push_back(pos_rogaliki[i].second);
    }

    long long il_przestawien2 = 1e18;

    for (int i = 0; i < min(300, n); i++) {
        for (int j = 0; j < min(300, n); j++) {
            for (int k = 0; k < min(300, n); k++) {
                long long tmp = il_przestawien;

                if (posortowane[0][i] == posortowane[1][j] ||
                    posortowane[0][i] == posortowane[2][k] ||
                    posortowane[1][j] == posortowane[2][k])
                    continue;

                tmp += max({drozdzowki[posortowane[0][i]],
                            paczki[posortowane[0][i]],
                            rogaliki[posortowane[0][i]]}) -
                       drozdzowki[posortowane[0][i]];

                tmp += max({drozdzowki[posortowane[1][j]],
                            paczki[posortowane[1][j]],
                            rogaliki[posortowane[1][j]]}) -
                       paczki[posortowane[1][j]];

                tmp += max({drozdzowki[posortowane[2][k]],
                            paczki[posortowane[2][k]],
                            rogaliki[posortowane[2][k]]}) -
                       rogaliki[posortowane[2][k]];

                il_przestawien2 = min(il_przestawien2, tmp);
            }
        }
    }

    cout << il_przestawien2 << "\n";
}