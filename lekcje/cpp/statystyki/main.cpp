#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool czypalindrom(string slowo)
{
    for (auto &i : slowo) {
        i = tolower(i);
    }
    string rev = slowo;
    reverse(rev.begin(), rev.end());
    return (rev == slowo && slowo.length() > 0);
}

int main()
{
    int il_danych;
    cin >> il_danych;
    int kolejnosc_danych[il_danych], dane[il_danych];
    for (auto &i : kolejnosc_danych) {
        cin >> i;
    }
    string tekst;
    cin >> tekst;
    for (int i = 0; i < il_danych; i++) {
        switch (i)
        {
        case 1:
            dane[i] = regex_search(text, " ")
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }
}