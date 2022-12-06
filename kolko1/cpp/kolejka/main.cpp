#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_polecen, liczba, usunieta;
    char operacja;
    queue<int> kolejka;
    cin >> il_polecen;
    for (int i = 0; i < il_polecen; i++) {
        cin >> operacja;
        if (operacja == '+') {
            cin >> liczba;
            kolejka.push(liczba);
        } else if (operacja == '-') {
            usunieta = kolejka.front();
            kolejka.pop();
            cout << usunieta << "\n";
        }
    }
}