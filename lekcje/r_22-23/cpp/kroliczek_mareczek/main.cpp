#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
long long biore[MAXN], niebiore[MAXN], marcheweczka, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> marcheweczka;
        biore[i] = niebiore[i - 1] + marcheweczka;
        niebiore[i] = max(biore[i - 1], niebiore[i - 1]);
    }
    cout << max(biore[n], niebiore[n]);
}