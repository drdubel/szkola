#include <bits/stdc++.h>
using namespace std;

int dl_danych;

int GcdOfArray(vector<int>& liczby, int idx)
{
    if (idx == dl_danych - 1) {
        return liczby[idx];
    }
    int a = liczby[idx];
    int b = GcdOfArray(liczby, idx + 1);
    return __gcd(a, b);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> dl_danych;
    vector<int> liczby;
    int liczba;
    for (int i = 0; i < dl_danych; i++) {
        cin >> liczba;
        liczby.push_back(liczba);
    }
    cout << GcdOfArray(liczby, 0) << "\n";
}