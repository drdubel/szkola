#include <iostream>

using namespace std;

const int MAXN = 5e5 + 7;
int sumy_prefiksowe[MAXN];
int il_murow, szer_wawozu, mur, liczba, wynik = 1e6 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> il_murow >> szer_wawozu;
    for (int i = 1; i <= il_murow; i++) {
        cin >> mur;
        if (i % 2 == 0) {
            sumy_prefiksowe[1]++;
            sumy_prefiksowe[mur + 1]--;
        } else {
            sumy_prefiksowe[szer_wawozu - mur + 1]++;
            sumy_prefiksowe[szer_wawozu + 1]--;
        }
    }
    for (int i = 1; i <= szer_wawozu; i++) {
        sumy_prefiksowe[i] += sumy_prefiksowe[i - 1];
        if (wynik == sumy_prefiksowe[i])
            liczba++;
        else if (sumy_prefiksowe[i] < wynik) {
            liczba = 1;
            wynik = sumy_prefiksowe[i];
        }
    }
    cout << wynik << " " << liczba;

    return 0;
}