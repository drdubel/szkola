#include <iostream>
#include <unordered_set>

using namespace std;

void szukaj_podslowa(int wym_il_roznych_liter, string tekst) {
    unordered_set<char> uzyte_litery;
    char akt_litera;
    int tyl = 1, przod = 0, akt_il_roznych_liter = 0;
    while (przod < tekst.size()) {
        przod++;
        akt_litera = tekst[przod];
        if (uzyte_litery.find(akt_litera) == uzyte_litery.end()) {
            uzyte_litery.insert(akt_litera);
            akt_il_roznych_liter++;
        } else if (akt_il_roznych_liter < wym_il_roznych_liter) {
            continue;
        }
    }
}

int main() {
    string tekst;
    int wym_il_roznych_liter;
    cin >> tekst >> wym_il_roznych_liter;
}