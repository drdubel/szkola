#include <iostream>
#include <stack>

using namespace std;

constexpr int MAXN = 2.5e5 + 7;
int budynki[MAXN];
stack<int> stos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, _, ilosc_plakatow = 0;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> _ >> budynki[i];

        while (!stos.empty() && budynki[i] < stos.top()) stos.pop();

        if (stos.empty() || stos.top() < budynki[i]) {
            stos.push(budynki[i]);
            ++ilosc_plakatow;
        }
    }
    cout << ilosc_plakatow;
}