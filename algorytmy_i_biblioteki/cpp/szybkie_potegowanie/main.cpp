#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll wynik;

ll pot(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0)
        return pow(pot(x, n / 2), 2);
    else
        return pot(x, n - 1) * x;
}
