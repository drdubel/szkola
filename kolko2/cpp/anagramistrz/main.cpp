#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string slowo1, slowo2, podciag1, podciag2;
    int i1 = 0, i2 = 0, minn, dl = 0;
    int liczba1[26], liczba2[26];
    cin >> slowo1 >> slowo2;
    for (i1 = 0; i1 < 26; i1++) {
        liczba1[i1] = 0;
        liczba2[i1] = 0;
    }
    for (i1 = 0; i1 < slowo1.size(); i1++) {
        liczba1[slowo1[i1] - 'a']++;
    }
    for (i2 = 0; i2 < slowo2.size(); i2++) {
        liczba2[slowo2[i2] - 'a']++;
    }
    for (i1 = 0; i1 < 26; i1++) {
        minn = min(liczba1[i1], liczba2[i1]);
        dl += minn;
        liczba1[i1] = minn;
        liczba2[i1] = minn;
    }
    for (auto it : slowo1) {
        if (liczba1[it - 'a'] > 0) {
            podciag1 += it;
            liczba1[it - 'a']--;
        }
    }
    for (auto it : slowo2) {
        if (liczba2[it - 'a'] > 0) {
            podciag2 += it;
            liczba2[it - 'a']--;
        }
    }
    if (dl == 0)
        puts("BRAK");
    else
        cout << dl << "\n" << podciag1 << "\n" << dl << "\n" << podciag2;
}