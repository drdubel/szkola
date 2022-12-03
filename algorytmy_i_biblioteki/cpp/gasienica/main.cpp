#include <iostream>

using namespace std;

int wagony[1000001];

int gasienica(int n, int ilec) {
    int wyn = 1000001, glowa = 0, ogon = 1, akt_sum = 0;
    while (glowa < n) {
        glowa++;
        akt_sum += wagony[glowa];
        if (akt_sum < ilec) {
            continue;
        }
        if (akt_sum == ilec) {
            wyn = min(wyn, glowa - ogon + 1);
        }
        while (ogon < glowa && akt_sum >= ilec) {
            akt_sum -= wagony[ogon];
            ogon++;
            if (akt_sum == ilec) {
                wyn = min(wyn, glowa - ogon + 1);
            }
        }
    }
    return wyn;
}