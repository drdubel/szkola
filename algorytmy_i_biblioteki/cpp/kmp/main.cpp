#include <algorithm>
#include <iostream>
using namespace std;

const long long MAXN = 16 * 1e6 + 7;
int dlugosci[MAXN];
string wzorzec, tekst, niepotrzebny_znak = "$";
long long dl_wzorca, dl_tekstu, i = 1, j;

void znajdz_wystapienia(const string &tekst, int dlugosci[]) {
    dlugosci[0] = -1;
    dlugosci[1] = 0;
    long long l = 0;
    for (long long i = 2; i < tekst.size(); i++) {
        while (l >= 0 && tekst[l + 1] != tekst[i]) l = dlugosci[l];
        l++;
        dlugosci[i] = l;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> dl_wzorca >> dl_tekstu;
    cin >> wzorzec >> tekst;
    tekst = niepotrzebny_znak + wzorzec + niepotrzebny_znak + tekst;

    znajdz_wystapienia(tekst, dlugosci);

    dl_wzorca = tekst.length();
    dl_tekstu = wzorzec.length();

    for (long long i = dl_tekstu + 1; i < tekst.length(); i++)
        if (dlugosci[i] == wzorzec.length())
            cout << i - (long long)wzorzec.length() - dl_tekstu << "\n";
}
