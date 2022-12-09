#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> goscie(n);
    for (int i = 0; i < n; i++) {
        cin >> goscie[i];
    }
    vector<bool> odwiedzeni(n, false);
    int stolików = 0;
    for (int i = 0; i < n; i++) {
        if (odwiedzeni[i]) continue;
        stolików++;
        int gosc = goscie[i];
        while (!odwiedzeni[gosc - 1]) {
            odwiedzeni[gosc - 1] = true;
            gosc = goscie[gosc - 1];
        }
    }
    cout << stolików << "\n";
}