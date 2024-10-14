#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> liczby_fib = {1, 1};

void fib(long long n) {
    while (liczby_fib[liczby_fib.size() - 1] < n) {
        liczby_fib.push_back(liczby_fib[liczby_fib.size() - 1] +
                             liczby_fib[liczby_fib.size() - 2]);
    }

    liczby_fib.pop_back();
}

long long najmniejsza_plansza(long long m, long long depth = 0) {
    if (m == 1)
        if (depth != 0)
            return depth - 1;
        else
            return 1;

    long long n = 1e18;

    for (int i = 2; i < liczby_fib.size(); ++i) {
        long long l = liczby_fib[i];

        if (l > m) break;

        if (m % l == 0) {
            int x = (find(liczby_fib.begin(), liczby_fib.end(), l) -
                     liczby_fib.begin());
            n = min(n, najmniejsza_plansza(m / l, depth + 1) + x);
        }
    }

    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;

    cin >> m;

    fib(1e18);
    n = najmniejsza_plansza(m);

    if (n == 1e18)
        cout << "NIE";
    else
        cout << n;
}