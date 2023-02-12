#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 2.1e6 + 7;
int tree[MAXN], base, a, b, n, m, i;
char op;
string initialState;

void change() {
    a += base - 1;
    b += base + 1;
    while (a / 2 != b / 2) {
        if (!(a & 1)) {
            ++tree[a + 1];
        }
        if (b & 1) {
            ++tree[b - 1];
        }
        a >>= 1;
        b >>= 1;
    }
}

bool getState() {
    a += base;
    long long res = 0;
    while (a > 0) {
        res += tree[a];
        a >>= 1;
    }
    return !(res & 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> initialState;
    base = pow(2, ceil(log2(n)));
    for (i = 0; i < n; ++i) {
        if (initialState[i] == 'x') tree[base + i] = 1;
    }
    for (i = 0; i < m; ++i) {
        cin >> op >> a;
        --a;
        if (op == 'S') {
            cin >> b;
            --b;
            change();
        } else {
            getState() ? cout << "ON\n" : cout << "OFF\n";
        }
    }
}
