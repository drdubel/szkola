#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<int, int> karty;
    vector<int> wyjscie;
    int n;
    cin >> n;
    int i, karta, a, b, nr = 1;
    for (i = 0; i < n; ++i) {
        cin >> karta;
        auto znal = karty.upper_bound(karta);
        if (znal == karty.end()) {
            wyjscie.push_back(-1);
            karty[karta] = nr++;
        } else {
            b = (*znal).second;
            karty.erase(znal);
            karty[karta] = b;
            wyjscie.push_back(b);
        }
    }
    cout << nr - 1 << '\n';
    for (i = 0; i < (int)wyjscie.size(); ++i) {
        if (wyjscie[i] == -1)
            cout << 1 << '\n';
        else
            cout << 2 << ' ' << wyjscie[i] << '\n';
    }
}