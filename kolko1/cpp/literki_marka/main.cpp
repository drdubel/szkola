#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string tekst;
    int il_roznych_liter;
    unordered_set<char> rozne_litery;
    cin >> tekst >> il_roznych_liter;
    for (char litera : tekst) {
        rozne_litery.insert(litera);
    }
    cout <<
}