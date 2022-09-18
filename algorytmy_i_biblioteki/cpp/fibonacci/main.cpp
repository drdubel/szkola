#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string dodawanie(string liczba1, string liczba2, int dl_liczb)
{
    int suma;
    int przeniesione = 0;
    string wynik = "";
    for (int i = dl_liczb - 1; i >= 0; i--)
    {
        suma = przeniesione + (int)(liczba1[i] - '0') + (int)(liczba2[i] - '0');
        wynik += '0' + (char)(suma % 10);
        przeniesione = suma / 10;
    }
    if (suma / 10 != 0)
    {
        wynik += '0' + (char)(suma / 10);
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}


string fib(int ktora)
{
    string liczba1 = "1";
    string liczba2 = "1";
    string wynik;
    for (int i = 2; i <= ktora; i++)
    {
        int dl_liczb = max(liczba1.size(), liczba2.size());
        if (dl_liczb > liczba1.size())
        {
            reverse(liczba1.begin(), liczba1.end());
            liczba1 += "0";
            reverse(liczba1.begin(), liczba1.end());
        }
        wynik = dodawanie(liczba1, liczba2, dl_liczb);
        liczba1 = liczba2;
        liczba2 = wynik;
    }
    return liczba2;
}


int main()
{
    int ktora;
    cin >> ktora;
    cout << fib(ktora) + "\n";
    return 0;
}