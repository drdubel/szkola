#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int il_osob;
    int pozycja = 0;
    int wydatki = 0;
    int i = il_osob - 1;
    cin >> il_osob;
    vector<int> ceny_przekupstwa(il_osob);
    for (auto &x : ceny_przekupstwa) {
        cin >> x;
    }

    cout << wydatki << "\n";
}