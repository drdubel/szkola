#include <iostream>
using namespace std;

int max(int x, int y) { return (x > y) ? x : y; }

int ciastkowybieracz(int pieniadze, int il_przedmiotow, int masa[],
                     int wartosc[]) {
    int i, wt;
    int tablica_wynikow[il_przedmiotow + 1][pieniadze + 1];
    for (i = 0; i <= il_przedmiotow; i++) {
        for (wt = 0; wt <= pieniadze; wt++) {
            if (i == 0 || wt == 0)
                tablica_wynikow[i][wt] = 0;
            else if (wartosc[i - 1] <= wt)
                tablica_wynikow[i][wt] = max(
                    masa[i - 1] + tablica_wynikow[i - 1][wt - wartosc[i - 1]],
                    tablica_wynikow[i - 1][wt]);
            else
                tablica_wynikow[i][wt] = tablica_wynikow[i - 1][wt];
        }
    }
    return tablica_wynikow[il_przedmiotow][pieniadze];
}

int main() {
    int il_przedmiotow, pieniadze;
    cin >> il_przedmiotow >> pieniadze;
    int masa[il_przedmiotow], wartosc[il_przedmiotow];
    for (int i = 0; i < il_przedmiotow; i++) {
        cin >> wartosc[i] >> masa[i];
    }
    cout << ciastkowybieracz(pieniadze, il_przedmiotow, masa, wartosc) << "\n";
}