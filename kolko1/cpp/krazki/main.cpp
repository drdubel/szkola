#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
int struktura_rury[MAXN], krazki[MAXN];
int il_walcow, il_krazkow, walec, i, j;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_walcow >> il_krazkow;
    struktura_rury[0] = 1e9 + 7;
    for (int i = 1; i <= il_walcow; i++) {
        cin >> walec;
        struktura_rury[i] = min(struktura_rury[i - 1], walec);
    }
    for (int i = 1; i <= il_krazkow; i++) cin >> krazki[i];

    i = il_walcow;
    j = 1;
    while (i > 0 && j <= il_walcow) {
        if (i <= 0 || j > il_walcow || krazki[j] == 0) break;
        do {
            i--;
        } while (struktura_rury[i] < krazki[j] && i > 0);
        j++;
    }
    cout << i;
}