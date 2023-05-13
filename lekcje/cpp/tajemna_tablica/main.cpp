#include <iostream>

#include "tajtabbibl.h"

using namespace std;
const int MINN = 1e9, MAXX = -1e9, MINI, MAXI;

void odp(int i) {
    int a = -1e9 - 7, e = 1e9 + 7, m;
    while (a < e) {
        m = (a + e) / 2;
        if (wieksze(i, m))
            a = m + 1;
        else
            e = m - 1;
    }
    --a;
    if (MAXX < a) {
        MAXX = max(MAXX, a);
        MAXI = i;
    }
    if (MINN > a) {
        MINN = min(MINN, a);
        MINI = i;
    }
}

int main() {
    int n = inicjuj();
    int a = -1e9 - 7, e = 1e9 + 7;
    for (int i = 0; i < n; ++i) odp(i);
    odpowiedz(MINI, MAXI);
}