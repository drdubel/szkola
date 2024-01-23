#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, liczba;
    cin >> n;
    map<int, int> ciag;
    pair<int, int> lider = {0, 0};
    for (int i = 0; i < n; ++i) {
        cin >> liczba;
        if (ciag.find(liczba) == ciag.end()) {
            ciag.insert({liczba, 1});
        } else {
            ciag[liczba] = ciag[liczba] + 1;
        }
        if (lider.second < ciag[liczba]) {
            lider = {liczba, ciag[liczba]};
        }
    }
    if (lider.second > n / 2)
        cout << lider.first;
    else
        cout << "NIE";
}