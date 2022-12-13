#include <algorithm>
#include <iostream>

using namespace std;

bool wieksze(string str1, string str2) {
    int dl_1 = str1.length(), dl_2 = str2.length();
    if (dl_1 < dl_2) {
        return 1;
    } else if (dl_1 == dl_2) {
        for (int i = 0; i < dl_1; i++) {
            if ((int)str1[i] > (int)str2[i]) {
                return 0;
            } else if ((int)str1[i] < (int)str2[i]) {
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il_slow;
    cin >> il_slow;
    string slowa[il_slow];
    for (string &slowo : slowa) {
        cin >> slowo;
    }
    sort(slowa, slowa + il_slow, wieksze);
    for (string slowo : slowa) {
        cout << slowo << "\n";
    }
}