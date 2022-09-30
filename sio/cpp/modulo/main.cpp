#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int liczba;
    vector<int> rozne_moduly;
    for (int i=0; i < 19; i++) {
        cin >> liczba;
        if (count(rozne_moduly.begin(), rozne_moduly.end(), liczba) == 0) {
            rozne_moduly.push_back(liczba);
        }
    }
    cout << rozne_moduly.size() << "\n";
}