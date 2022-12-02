#include <iostream>
using namespace std;


int nwd(int liczba1, int liczba2) {
    while (liczba2 != 0) {
        swap(liczba1, liczba2);
        liczba2 = liczba2 % liczba1;
    }
    return liczba1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dl_danych, liczba1, liczba2;
    scanf("%d%d", &dl_danych, &liczba1);
    for (int i = 1; i < dl_danych; i++) {
        scanf("%d", &liczba2);
        liczba1 = nwd(liczba1, liczba2);
    }
    cout << liczba1 << "\n";
}