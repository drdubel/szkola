#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 2e5 + 7;
pair<int, int> tab[MAXN];

int main() {
    int n, a, b, i;
    int topp = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> tab[i].second >> tab[i].first;
    }
    sort(tab, tab + n);
    int output = 0;
    pair<int, int> el;
    for (i = 0; i < n; ++i) {
        el = tab[i];
        if (el.second >= topp) {
            topp = el.first;
            ++output;
        }
    }
    cout << output;
}