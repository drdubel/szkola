#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 7;
int il_kontaktow, wartosc_w_tajtonach, numer, i;
pair<int, int> kontakty[MAXN];

int main() {
    cin >> il_kontaktow;
    for (i = 0; i < il_kontaktow; ++i) {
        wartosc_w_tajtonach = 0;
        cin >> kontakty[i].second;
        numer = kontakty[i].second;
        wartosc_w_tajtonach += numer % 10 * 100;
        wartosc_w_tajtonach += (numer % 100 - numer % 10);
        wartosc_w_tajtonach += (numer % 1000 - numer % 100) / 100;
        wartosc_w_tajtonach += (numer - numer % 1000);
        kontakty[i].first = wartosc_w_tajtonach;
    }
    sort(kontakty, kontakty + il_kontaktow);
    for (i = 0; i < il_kontaktow; ++i) {
        cout << kontakty[i].second << ' ';
    }
}