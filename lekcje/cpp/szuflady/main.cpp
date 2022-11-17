#include <iostream>
using namespace std;

int szufladowsuwacz(int *szuflady, int il_szuflad)
{
    int poprzednia_szuflada = 1000000001, il_wsuniec = 0;
    for (int i = il_szuflad - 1; i >= 0; i--)
    {
        int szuflada = szuflady[i];
        if (szuflada >= poprzednia_szuflada)
        {
            szuflada = poprzednia_szuflada - 1;
            il_wsuniec++;
            if (szuflada < 1) {
                return -1;
            }
        }
        poprzednia_szuflada = szuflada;
    }
    return il_wsuniec;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il_szuflad;
    cin >> il_szuflad;
    int szuflady[il_szuflad];
    for (auto &szuflada : szuflady)
    {
        cin >> szuflada;
    }
    cout << szufladowsuwacz(szuflady, il_szuflad) << endl;
}