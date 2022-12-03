#include <cmath>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long double liczba;
    cin >> liczba;
    liczba = floor(sqrt(liczba)) + 1;
    cout << (int)liczba << "\n";
}
