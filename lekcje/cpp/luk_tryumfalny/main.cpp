#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string tekst;
    getline(cin, tekst);
    tekst.erase(std::remove(tekst.begin(), tekst.end(), ' '), tekst.end());
    for (int i = 0; i < tekst.length(); i++)
    {
        char litera = tekst[i];
        if ((litera >= 97) & (litera <= 122))
        {
            tekst[i] = litera - 32;
        }
    }
    replace(tekst.begin(), tekst.end(), 'U', 'V');
    cout << tekst << "\n";
}