#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool czypalindrom(string slowo) {
    for (auto &i : slowo) {
        i = tolower(i);
    }
    string rev = slowo;
    reverse(rev.begin(), rev.end());
    return (rev == slowo && slowo.length() > 0);
}

int policz_wystapienia(string tekst, string wzorzec) {
    regex slowa(wzorzec);
    auto poczatek = sregex_iterator(tekst.begin(), tekst.end(), slowa);
    auto koniec = sregex_iterator();

    return distance(poczatek, koniec);
}

int main() {
    int il_danych;
    cin >> il_danych;
    int kolejnosc_danych[il_danych], dane[il_danych];
    for (auto &i : kolejnosc_danych) {
        cin >> i;
    }
    string tekst;
    cin >> tekst;
    for (int i = 0; i < il_danych; i++) {
        switch (kolejnosc_danych[i]) {
            case 1:
                dane[i] = policz_wystapienia(tekst, " ");
            case 2:
                dane[i] = policz_wystapienia(tekst, "[0-9]+");
            case 3:
                dane[i] = policz_wystapienia(tekst, "[a-zA-Z]+");
            case 4:
                dane[i] = policz_wystapienia(tekst, "([^.]*[a-zA-Z]+[^.]*\\.)");
            case 5:
                dane[i] = 0;
                regex slowa("[a-zA-Z]+");
                for (sregex_iterator it =
                         sregex_iterator(tekst.begin(), tekst.end(), slowa);
                     it != sregex_iterator(); it++) {
                    smatch match;
                    match = *it;
                    dane[i] += czypalindrom(match.str(0));
                }
        }
    }
    for (auto ilosc : dane) {
        cout << ilosc << ' ';
    }
}