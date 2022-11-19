#include <iostream>
#include <string>

using namespace std;

string szyfruj(int o_ile, string wiadomosc)
{
    string zaszyfrowana_wiadomosc = "";
    for (int i = 0; i < wiadomosc.length(); i++)
    {
        if ((wiadomosc[i] >= 'a') & (wiadomosc[i] <= 'z'))
        {
            zaszyfrowana_wiadomosc += ((wiadomosc[i] + o_ile) - 'a') % 26 + 'a';
        }
        else if ((wiadomosc[i] >= 'A') & (wiadomosc[i] <= 'Z'))
        {
            zaszyfrowana_wiadomosc += ((wiadomosc[i] + o_ile) - 'A') % 26 + 'A';
        }
        else
        {
            zaszyfrowana_wiadomosc += wiadomosc[i];
        }
    }
    return zaszyfrowana_wiadomosc;
}

string odszyfruj(int o_ile, string zaszyfrowana_wiadomosc)
{
    string odszyfrowana_wiadomosc = "";
    for (int i = 0; i < zaszyfrowana_wiadomosc.length(); i++)
    {
        if ((zaszyfrowana_wiadomosc[i] >= 'a') & (zaszyfrowana_wiadomosc[i] <= 'z'))
        {
            if (((zaszyfrowana_wiadomosc[i] - o_ile) - 'a') < 0)
            {
                odszyfrowana_wiadomosc += zaszyfrowana_wiadomosc[i] - o_ile - 'a' + 26 + 'a';
            }
            else
            {
                odszyfrowana_wiadomosc += zaszyfrowana_wiadomosc[i] - o_ile - 'a' + 'a';
            }
        }
        else if ((zaszyfrowana_wiadomosc[i] >= 'A') & (zaszyfrowana_wiadomosc[i] <= 'Z'))
        {
            if (((zaszyfrowana_wiadomosc[i] - o_ile) - 'A') < 0)
            {
                odszyfrowana_wiadomosc += zaszyfrowana_wiadomosc[i] - o_ile - 'A' + 26 + 'A';
            }
            else
            {
                odszyfrowana_wiadomosc += zaszyfrowana_wiadomosc[i] - o_ile - 'A' + 'A';
            }
        }
        else
        {
            odszyfrowana_wiadomosc += zaszyfrowana_wiadomosc[i];
        }
    }
    return odszyfrowana_wiadomosc;
}

int main()
{
    string co_robic;
    int o_ile;
    string wiadomosc;
    cin >> co_robic >> o_ile >> ws;
    getline(cin, wiadomosc);
    if (co_robic == "szyfruj")
    {
        cout << szyfruj(o_ile, wiadomosc) << "\n";
    }
    else if (co_robic == "odszyfruj")
    {
        cout << odszyfruj(o_ile, wiadomosc) << "\n";
    }
}