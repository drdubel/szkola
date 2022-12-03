#include <iostream>

using namespace std;
long long maxSum(int arr[], int il_kocertow, int il_planowanych_koncertow) {
    long long wynik = 0;
    for (int i = 0; i < il_planowanych_koncertow; i++) wynik += arr[i];
    long long akt_wynik = wynik;
    for (int i = il_planowanych_koncertow; i < il_kocertow; i++) {
        akt_wynik += arr[i] - arr[i - il_planowanych_koncertow];
        wynik = max(wynik, akt_wynik);
    }

    return wynik;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_koncertow, il_planowanych_koncertow;
    cin >> il_koncertow >> il_planowanych_koncertow;
    int koncerty[il_koncertow];
    for (auto &koncert : koncerty) {
        cin >> koncert;
        koncert *= -1;
    }
    cout << -maxSum(koncerty, il_koncertow, il_planowanych_koncertow) << "\n";
}
