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

string usun_zera_koncowe(string liczba) {
    if (liczba.find_last_not_of('0') == -1) {
        return "0";
    }
    liczba.erase(liczba.find_last_not_of('0') + 1, liczba.length());
    if (liczba[liczba.length() - 1] == ',') {
        liczba.erase(liczba.length() - 1, liczba.length());
    }
    return liczba;
}

string dodawanie(string liczba1, string liczba2, bool odw = false) {
    int suma, dl_krotsza, dl_dluzsza, przeniesione = 0,
                                      dl_liczby1 = liczba1.length(),
                                      dl_liczby2 = liczba2.length();
    dl_krotsza = min(dl_liczby1, dl_liczby2);
    dl_dluzsza = max(dl_liczby1, dl_liczby2);
    string wynik;
    if (!odw) {
        for (int i = dl_dluzsza - dl_krotsza; i > 0; i--) {
            if (dl_liczby1 < dl_liczby2) {
                liczba1 = "0" + liczba1;
            } else {
                liczba2 = "0" + liczba2;
            }
        }
    } else {
        for (int i = dl_dluzsza - dl_krotsza; i > 0; i--) {
            if (dl_liczby1 < dl_liczby2) {
                liczba1 = liczba1 + "0";
            } else {
                liczba2 = liczba2 + "0";
            }
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

string odejmowanie(string liczba1, string liczba2, bool odw = false) {
    bool ujemny = false;

    if (czy_mniejsze(liczba1, liczba2)) {
        swap(liczba1, liczba2);
        ujemny = true;
    }

    int roznica, dl_krotsza, dl_dluzsza, przeniesione = 0;
    int dl_liczby1 = liczba1.length();
    int dl_liczby2 = liczba2.length();

    dl_krotsza = min(dl_liczby1, dl_liczby2);
    dl_dluzsza = max(dl_liczby1, dl_liczby2);

    string wynik;
    if (!odw) {
        for (int i = dl_dluzsza - dl_krotsza; i > 0; i--) {
            if (dl_liczby1 < dl_liczby2) {
                liczba1 = "0" + liczba1;
            } else {
                liczba2 = "0" + liczba2;
            }
        }
    } else {
        for (int i = dl_dluzsza - dl_krotsza; i > 0; i--) {
            if (dl_liczby1 < dl_liczby2) {
                liczba1 = liczba1 + "0";
            } else {
                liczba2 = liczba2 + "0";
            }
        }
        if (czy_mniejsze(liczba1, liczba2)) {
            swap(liczba1, liczba2);
            ujemny = !ujemny;
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

    if (!odw)
        wynik.erase(0, min(wynik.find_first_not_of('0'), wynik.length() - 1));
    else {
        wynik = usun_zera_koncowe(wynik);
    }
    if (ujemny) {
        wynik = "-" + wynik;
    }

    return wynik;
}

string dodawanie_ulamkow(string liczba1, string liczba2) {
    int dl_calosci1 = liczba1.find(',');
    int dl_calosci2 = liczba2.find(',');
    string czesc_calkowita1 = liczba1.substr(0, dl_calosci1);
    string czesc_calkowita2 = liczba2.substr(0, dl_calosci2);
    string czesc_ulamkowa1 = "0", czesc_ulamkowa2 = "0";
    if (dl_calosci1 != -1) {
        czesc_ulamkowa1 =
            liczba1.substr(dl_calosci1 + 1, liczba1.length() - dl_calosci1 - 1);
    }
    if (dl_calosci2 != -1) {
        czesc_ulamkowa2 =
            liczba2.substr(dl_calosci2 + 1, liczba2.length() - dl_calosci2 - 1);
    }
    string suma_calosci = dodawanie(czesc_calkowita1, czesc_calkowita2);
    string suma_ulamkow = dodawanie(czesc_ulamkowa1, czesc_ulamkowa2, true);
    if (suma_ulamkow.length() >
        max(czesc_ulamkowa1.length(), czesc_ulamkowa2.length())) {
        suma_calosci = dodawanie(suma_calosci, "1");
        suma_ulamkow.erase(0, 1);
    }
    string suma_liczb = suma_calosci + "," + suma_ulamkow;
    return suma_liczb;
}

string odejmowanie_ulamkow(string liczba1, string liczba2) {
    int dl_calosci1 = liczba1.find(',');
    int dl_calosci2 = liczba2.find(',');
    string czesc_calkowita1 = liczba1.substr(0, dl_calosci1);
    string czesc_calkowita2 = liczba2.substr(0, dl_calosci2);
    string czesc_ulamkowa1 = "0", czesc_ulamkowa2 = "0";
    if (dl_calosci1 != -1) {
        czesc_ulamkowa1 =
            liczba1.substr(dl_calosci1 + 1, liczba1.length() - dl_calosci1 - 1);
    }
    if (dl_calosci2 != -1) {
        czesc_ulamkowa2 =
            liczba2.substr(dl_calosci2 + 1, liczba2.length() - dl_calosci2 - 1);
    }
    string roznica_calosci = odejmowanie(czesc_calkowita1, czesc_calkowita2);

    string roznica_ulamkow =
        odejmowanie(czesc_ulamkowa1, czesc_ulamkowa2, true);
    if (roznica_ulamkow == "0") {
    } else if (roznica_ulamkow[0] == '-') {
        roznica_ulamkow.erase(0, 1);
        if (roznica_calosci == "0") {
            roznica_calosci = "-" + roznica_calosci;
        } else if (roznica_calosci[0] != '-') {
            roznica_calosci = odejmowanie(roznica_calosci, "1");
            roznica_ulamkow = odejmowanie(
                "1" + string(roznica_ulamkow.length(), '0'), roznica_ulamkow);
        }
    } else {
        if (roznica_calosci == "0") {
        } else if (roznica_calosci[0] == '-') {
            roznica_calosci.erase(0, 1);
            roznica_calosci = odejmowanie(roznica_calosci, "1");
            roznica_ulamkow = odejmowanie(
                "1" + string(roznica_ulamkow.length(), '0'), roznica_ulamkow);
        }
    }
    string roznica_liczb = roznica_calosci + "," + roznica_ulamkow;
    return roznica_liczb;
}

string dodaj(string liczba1, string liczba2) {
    if (liczba2[0] == '+') {
        liczba2.erase(0, 1);
    }
    if ((liczba1[0] == '-') && (liczba2[0] != '-')) {
        liczba1.erase(0, 1);
        return odejmowanie_ulamkow(liczba2, liczba1);
    } else if ((liczba1[0] != '-') && (liczba2[0] == '-')) {
        liczba2.erase(0, 1);
        return odejmowanie_ulamkow(liczba1, liczba2);
    } else if ((liczba1[0] == '-') && (liczba2[0] == '-')) {
        liczba1.erase(0, 1);
        liczba2.erase(0, 1);
        return "-" + dodawanie_ulamkow(liczba1, liczba2);
    } else {
        return dodawanie_ulamkow(liczba1, liczba2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    string wynik, liczba;
    cin >> n >> wynik;
    for (i = 0; i < n - 1; ++i) {
        cin >> liczba;
        wynik = dodaj(wynik, liczba);
    }
    wynik = usun_zera_koncowe(wynik);
    cout << wynik << "\n";
}