#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 2e5 + 7;

struct punkt {
    int x, y;
    double kat;
};

punkt punkty[MAXN];
int ilPunktow, i;

bool porownajPol(punkt a, punkt b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool porownajKat(punkt a, punkt b) {
    if (a.kat != b.kat) return a.kat < b.kat;
    return (pow(a.x - punkty[0].x, 2) + pow(a.y - punkty[0].y, 2)) <
           (pow(b.x - punkty[0].x, 2) + pow(b.y - punkty[0].y, 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> ilPunktow;
    for (i = 0; i < ilPunktow; ++i) {
        cin >> punkty[i].x >> punkty[i].y;
    }
    sort(punkty, punkty + ilPunktow, porownajPol);
    for (int i = 1; i < ilPunktow; i++)
        punkty[i].kat =
            atan2((punkty[i].y - punkty[0].y), (punkty[i].x - punkty[0].x)) *
            180 / M_PI;

    sort(punkty + 1, punkty + ilPunktow, porownajKat);
    for (int i = 0; i < ilPunktow; i++)
        cout << punkty[i].x << " " << punkty[i].y << "\n";
}
