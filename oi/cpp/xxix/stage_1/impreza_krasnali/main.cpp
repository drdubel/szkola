#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 7;

int zle_czapki[MAXN], dobre_czapki[MAXN], n, i;
vector<int> byly;

int factmod(int x) {
    int p = 1e9 + 7;
    int wyn = 1;
    if (x >= p) return 0;
    for (i = 1; i <= x; i++) wyn = (wyn * i) % p;

    return wyn;
}

int il_kombinacji() {
    dobre_czapki[1] = zle_czapki[0];
    dobre_czapki[n - 2] = zle_czapki[n - 1];
    byly.push_back(zle_czapki[0]);
    byly.push_back(zle_czapki[n - 1]);
    for (i = 0; i < n - 1; ++i) {
        if (count(byly.begin(), byly.end(), zle_czapki[i])) {
            continue;
        }
        if (zle_czapki[i] == zle_czapki[i + 2] || dobre_czapki[i - 1] != 0) {
            dobre_czapki[i + 1] = zle_czapki[i];
            byly.push_back(zle_czapki[i]);
        } else {
            dobre_czapki[i - 1] = zle_czapki[i];
            byly.push_back(zle_czapki[i]);
        }
    } /*
     for (i = 0; i < n; ++i) {
         cout << dobre_czapki[i] << ' ';
     }
     cout << "\n";*/
    return factmod(count(dobre_czapki, dobre_czapki + n, 0));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (; i < n; ++i) {
        cin >> zle_czapki[i];
    }
    cout << il_kombinacji() << "\n";
}