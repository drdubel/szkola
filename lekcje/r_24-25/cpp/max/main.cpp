#include <deque>
#include <iostream>

using namespace std;

constexpr int MAXN = 2e5 + 7;
int ciag[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i < n + 1; i++) {
        cin >> ciag[i];
        ciag[i] += ciag[i - 1];
    }
}