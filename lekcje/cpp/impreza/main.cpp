#include <cmath>
#include <iostream>

using namespace std;

double sredni_wiek = 18;
int n, wiek, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> wiek;
        sredni_wiek += wiek;
    }
    cout << floor(sredni_wiek / (n + 1)) << "\n";
}