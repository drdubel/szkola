#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
int wagony[MAXN], n;

string gasienica(int ilec) {
    int glowa = 0, ogon = 1, akt_sum = 0;
    while (glowa < n) {
        glowa++;
        akt_sum += wagony[glowa];
        if (akt_sum < ilec) {
            continue;
        }
        if (akt_sum == ilec) {
            return "TAK";
        }
        while (ogon < glowa && akt_sum >= ilec) {
            akt_sum -= wagony[ogon];
            ogon++;
            if (akt_sum == ilec) {
                return "TAK";
            }
        }
    }
    return "NIE";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> wagony[i];
    }
    cout << gasienica(2137) << "\n";
}