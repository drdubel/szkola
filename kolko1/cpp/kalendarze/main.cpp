#include <iostream>
using namespace std;

const int MAXN = 1e6 + 7;
int dl_miesiecy_a[MAXN], dl_miesiecy_b[MAXN];
int il_miesiecy_a, il_miesiecy_b, il_zapytan, dzien, miesiac;
long long poczatek, koniec, srodek, res;
char plemie;

int zamiana_kalendarzy(int arr[], long long poczatek, long long koniec,
                       long long szukany_dzien) {
    while (poczatek <= koniec) {
        srodek = (poczatek + koniec) / 2;
        if (arr[srodek] <= szukany_dzien) {
            poczatek = srodek + 1;
            res = srodek;
        } else
            koniec = srodek - 1;
    }
    if (arr[res] < szukany_dzien) return res + 1;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> il_miesiecy_a >> il_miesiecy_b;
    for (i = 1; i <= il_miesiecy_a; i++) {
        cin >> dl_miesiecy_a[i];
        dl_miesiecy_a[i] += dl_miesiecy_a[i - 1];
    }
    for (i = 1; i <= il_miesiecy_b; i++) {
        cin >> dl_miesiecy_b[i];
        dl_miesiecy_b[i] += dl_miesiecy_b[i - 1];
    }

    cin >> il_zapytan;
    for (i = 0; i < il_zapytan; i++) {
        cin >> dzien >> miesiac >> plemie;
        if (plemie == 'A') {
            dzien += dl_miesiecy_a[miesiac - 1];
            if (dzien < dl_miesiecy_b[1])
                cout << dzien << " " << 1 << "\n";
            else
                cout << dzien - dl_miesiecy_b[zamiana_kalendarzy(
                                                  dl_miesiecy_b, 1,
                                                  il_miesiecy_b, dzien) -
                                              1]
                     << " "
                     << zamiana_kalendarzy(dl_miesiecy_b, 1, il_miesiecy_b,
                                           dzien)
                     << "\n";
        } else if (plemie == 'B') {
            dzien = dl_miesiecy_b[miesiac - 1] + dzien;
            if (dzien < dl_miesiecy_a[1])
                cout << dzien << " " << 1 << "\n";
            else
                cout << dzien - dl_miesiecy_a[zamiana_kalendarzy(
                                                  dl_miesiecy_a, 1,
                                                  il_miesiecy_a, dzien) -
                                              1]
                     << " "
                     << zamiana_kalendarzy(dl_miesiecy_a, 1, il_miesiecy_a,
                                           dzien)
                     << "\n";
        }
    }
}
