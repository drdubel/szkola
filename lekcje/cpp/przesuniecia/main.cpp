#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int il_liczb, przesuniecie, liczba, i;
    cin >> il_liczb >> przesuniecie;
    int do_przesuniecia[przesuniecie];
    for (auto &liczba : do_przesuniecia)
    {
        cin >> liczba;
    }
    for (i = 0; i < il_liczb - przesuniecie; i++)
    {
        cin >> liczba;
        cout << liczba << ' ';
    }
    for (i = 0; i < przesuniecie; i++)
    {
        cout << do_przesuniecia[i] << ' ';
    }
    cout << "\n";
}