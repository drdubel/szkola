#include <iostream>
#define INFINITY 2147483647
using namespace std;

int main()
{
    int il_monet, reszta;
    cin >> il_monet >> reszta;
    int *mozliwosci = new int[reszta + 1];
    mozliwosci[0] = 0;
    int i;
    for (i = 1; i <= reszta; i++)
    {
        mozliwosci[i] = INFINITY;
    }
    for (i = 1; i <= il_monet; i++)
    {
        int moneta;
        cin >> moneta;
        for (int j = 0; j <= reszta - moneta; j++)
        {
            if (mozliwosci[j] < INFINITY)
            {
                if (mozliwosci[j] + 1 < mozliwosci[j + moneta])
                {
                    mozliwosci[j + moneta] = mozliwosci[j] + 1;
                }
            }
        }
    }
    if (mozliwosci[reszta] == INFINITY)
    {
        cout << "NIE\n";
    }
    else
    {
        cout << mozliwosci[reszta] << "\n";
    }
}