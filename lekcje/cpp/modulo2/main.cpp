#include <iostream>
#include <set>
using namespace std;

int main() {
    int il_liczb, modulo;
    long long liczba;
    cin >> il_liczb >> modulo;
    set<long long> reszty;
    for (int i = 0; i < il_liczb; i++) {
        cin >> liczba;
        reszty.insert(liczba % modulo);
    }
    cout << reszty.size() << "\n";
}