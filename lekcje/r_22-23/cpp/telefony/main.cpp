#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
int il_kontaktow, numer, i;
pair<int, int> kontakty[MAXN];

int main() {
    cin >> il_kontaktow;
    for (i = 0; i < il_kontaktow; ++i) {
        cin >> kontakty[i].second;
        numer = kontakty[i].second;
        kontakty[i].first += numer % 10 * 100;
        kontakty[i].first += (numer % 100 - numer % 10);
        kontakty[i].first += (numer % 1000 - numer % 100) / 100;
        kontakty[i].first += (numer - numer % 1000);
    }
    sort(kontakty, kontakty + il_kontaktow);
    for (i = 0; i < il_kontaktow; ++i) {
        cout << kontakty[i].second << ' ';
    }
}