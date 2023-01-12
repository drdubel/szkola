#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_planow, il_zajec, i, j, min, max;
    string wypisz;
    cin >> il_planow;
    for (j = 0; j < il_planow; j++) {
        wypisz = "TAK\n";
        cin >> il_zajec;
        pair<int, int> temperatury[il_zajec * 2];
        for (i = 0; i < il_zajec * 2; i += 2) {
            cin >> min >> max;
            temperatury[i] = make_pair(min, 1);
            temperatury[i + 1] = make_pair(max, 0);
        }
        sort(temperatury, temperatury + il_zajec * 2);
        for (i = 1; i < il_zajec * 2; i++) {
            if ((temperatury[i].first != temperatury[i - 1].first) &
                (temperatury[i].second == temperatury[i - 1].second)) {
                wypisz = "NIE\n";
                break;
            }
        }
        cout << wypisz;
    }
}
