#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int ilosc_liczb;
    cin >> ilosc_liczb;
    int ciag_liczb[ilosc_liczb];
    for (int i = 0; i < ilosc_liczb; i++) {
        cin >> ciag_liczb[i];
    }
    sort(ciag_liczb, ciag_liczb + ilosc_liczb);
    int roznica = ciag_liczb[ilosc_liczb - 1] - ciag_liczb[0];
    cout << roznica << endl;
}
