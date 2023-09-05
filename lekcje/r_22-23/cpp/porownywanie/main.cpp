#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool czy_mniejsze(string liczba1, string liczba2) {
    int l1 = liczba1.length(), l2 = liczba2.length();

    if (l1 < l2) return true;
    if (l1 > l2) return false;

    for (int i = 0; i < l1; i++) {
        if (liczba1[i] < liczba2[i])
            return true;
        else if (liczba1[i] > liczba2[i])
            return false;
    }

    return false;
}

string dodawanie(string liczba1, string liczba2) {
    int suma, dl_krotsza, dl_dluzsza, przeniesione = 0,
                                      dl_liczby1 = liczba1.size(),
                                      dl_liczby2 = liczba2.size();
    dl_krotsza = min(dl_liczby1, dl_liczby2);
    dl_dluzsza = max(dl_liczby1, dl_liczby2);
    string wynik;
    for (int i = dl_dluzsza - dl_krotsza; i > 0; i--) {
        if (dl_liczby1 < dl_liczby2) {
            liczba1 = "0" + liczba1;
        } else {
            liczba2 = "0" + liczba2;
        }
    }
    for (int i = dl_dluzsza - 1; i >= 0; i--) {
        suma = przeniesione + (int)(liczba1[i] - '0') + (int)(liczba2[i] - '0');
        wynik += '0' + (char)(suma % 10);
        przeniesione = suma / 10;
    }
    if (suma / 10 != 0) {
        wynik += '0' + (char)(suma / 10);
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}
string odejmowanie(string liczba1, string liczba2) {
    bool ujemny = false;

    if (czy_mniejsze(liczba1, liczba2)) {
        swap(liczba1, liczba2);
        ujemny = true;
    }

    int roznica, dl_krotsza, dl_dluzsza, przeniesione = 0;
    int dl_liczby1 = liczba1.size();
    int dl_liczby2 = liczba2.size();

    dl_krotsza = min(dl_liczby1, dl_liczby2);
    dl_dluzsza = max(dl_liczby1, dl_liczby2);

    string wynik;

    for (int i = dl_dluzsza - dl_krotsza; i > 0; i--) {
        if (dl_liczby1 < dl_liczby2) {
            liczba1 = "0" + liczba1;
        } else {
            liczba2 = "0" + liczba2;
        }
    }

    for (int i = dl_dluzsza - 1; i >= 0; i--) {
        roznica =
            (int)(liczba1[i] - '0') - (int)(liczba2[i] - '0') - przeniesione;

        if (roznica < 0) {
            roznica += 10;
            przeniesione = 1;
        } else {
            przeniesione = 0;
        }

        wynik += '0' + (char)(roznica);
    }

    reverse(wynik.begin(), wynik.end());

    wynik.erase(0, min(wynik.find_first_not_of('0'), wynik.size() - 1));

    if (ujemny) {
        wynik = "-" + wynik;
    }

    return wynik;
}

string dodaj(string liczba1, string liczba2) {
    if ((liczba1[0] == '-') && (liczba2[0] != '-')) {
        liczba1.erase(0, 1);
        return odejmowanie(liczba2, liczba1);
    } else if ((liczba1[0] != '-') && (liczba2[0] == '-')) {
        liczba2.erase(0, 1);
        return odejmowanie(liczba1, liczba2);
    } else if ((liczba1[0] == '-') && (liczba2[0] == '-')) {
        liczba1.erase(0, 1);
        liczba2.erase(0, 1);
        return "-" + dodawanie(liczba1, liczba2);
    } else {
        return dodawanie(liczba1, liczba2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string liczba1, liczba2, wynik1, wynik2;
    cin >> liczba1 >> liczba2;
    wynik1 = dodaj(liczba1, liczba2);
    cin >> liczba1 >> liczba2;
    wynik2 = dodaj(liczba1, liczba2);
    if (wynik1 == wynik2) {
        cout << "ROWNE\n";
    } else if ((wynik1[0] == '-') && (wynik2[0] != '-')) {
        cout << "MNIEJSZE\n";
    } else if ((wynik1[0] != '-') && (wynik2[0] == '-')) {
        cout << "WIEKSZE\n";
    } else if ((wynik1[0] == '-') && (wynik2[0] == '-')) {
        wynik1.erase(0, 1);
        wynik2.erase(0, 1);
        if (czy_mniejsze(wynik1, wynik2)) {
            cout << "WIEKSZE\n";
        } else {
            cout << "MNIEJSZE\n";
        }
    } else {
        if (czy_mniejsze(wynik1, wynik2)) {
            cout << "MNIEJSZE\n";
        } else {
            cout << "WIEKSZE\n";
        }
    }
}
