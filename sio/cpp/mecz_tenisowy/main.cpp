#include <iostream>
#include <stdlib.h>
using namespace std;

string input;
int indeks = 0;

bool ktory(int minwynik) {
    int zlicz1 = 0, zlicz2 = 0;
    while ((zlicz1 < minwynik && zlicz2 < minwynik) || abs(zlicz1, zlicz2) < 2)
    {
        if (input[indeks] == 'A')
            ++zlicz1;
        else
            ++zlicz2;
        ++indeks;
    }
    if (zlicz1 > zlicz2)
        return 0;
    else
        return 1;
}

int main() {
    cin >> input;
    bool wynik;
    int g1 = 0, g2 = 0, s1 = 0, s2 = 0;

    while (max(s1, s2) < 3 && indeks < input.length()) {
        wynik = ktory(4);
        if (!wynik)
            ++g1;
        else
            ++g2;
        if (g1 == 6 && g2 == 6) {
            wynik = ktory(7);
            if (!wynik) {
                ++s1;
            }
            else {
                ++s2;
            }
            g1 = 0;
            g2 = 0;
        }
        else if (g1 >= 6 && g1 - g2 >= 2) {
            ++s1;
            g1 = 0, g2 = 0;
        }
        else if (g2 >= 6 && g2 - g1 >= 2) {
            ++s2;
            g1 = 0, g2 = 0;
        }
    }
    cout << ((s1 == 3) ? 'A' : 'B');
}
