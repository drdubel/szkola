#include <iostream>

using namespace std;

bool czy_pierwsza[16000000];

void sito_erastotenesa(long ile_wypisac) {
    int i = 1;
    czy_pierwsza[0] = false;
    for (long i = 1; i < 16000000; i++){
        czy_pierwsza[i] = true;
    }
    while (i < 16000000 && ile_wypisac > 0) {
        if (czy_pierwsza[i] == true){
            for (long j = i; j < 16000000; j += (i+1)){
                czy_pierwsza[j] = false;
            }
            czy_pierwsza[i] = true;
            cout << i+1 << "\n";
            ile_wypisac--;
        }
        i++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long liczba;
    cin >> liczba;
    sito_erastotenesa(liczba);
}
