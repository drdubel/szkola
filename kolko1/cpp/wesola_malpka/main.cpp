#include <iostream>
using namespace std;

int nwd(int liczba1, int liczba2)
{
    int liczba3;
    
	while(liczba2!=0)
    {
		liczba3 = liczba2;
		liczba2 = liczba1%liczba2;
		liczba1 = liczba3;	
	}
	
    return liczba1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, liczba_klatek, dl_skoku;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> liczba_klatek >> dl_skoku;
        cout << liczba_klatek / nwd(liczba_klatek, dl_skoku) << "\n";
    }
}