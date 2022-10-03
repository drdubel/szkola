#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


bool czy_pierwsza(int liczba) {
	for (int i=2; i <= sqrt(liczba); i++) {
		if (liczba%i == 0) {
			return false;
		}
	}
    return true;
}


int main() {
    int ilosc_liczb;
    int liczba;
    cin >> ilosc_liczb;
    for (int i=0; i < ilosc_liczb; i++) {
        cin >> liczba;
        int lp1 = liczba/2;
        int lp2 = 0;
        while (lp1 + lp2 != liczba) {
            if (czy_pierwsza(lp1) && czy_pierwsza(liczba - lp1)) {
                lp2 = liczba - lp1;
                break;
            }
            lp1++;
        }
        cout << lp2 << " " << lp1 << "\n";
    }
}
