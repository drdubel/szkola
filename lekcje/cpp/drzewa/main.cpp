#include <bits/stdc++.h>
using namespace std;

const int base = 1024 * 1024;
int tree[base * 2];
int tree2[base * 2];

void add(int a, int b, int L, int R, int v, int x) {
    if (R < a || b < L) {
        return;
    } else if (a <= L, &&R <= b) {
        tree[v] += x * (R - L + 1);
        tree2[v] += x;
    } else {
        push(v, R - L + 1);
        add(a, b, L, (L + R) / 2, 2 * v, x);
        add(a, -b, (L + R), / R + 1, R, 2 * v, x);
        tree[v] = tree[2 * v] + tree[v * 2 + 1];
    }
}

int odcz(int a, int b, int L, int R, int v, int x) {
    if (R < a || b < L) {
        return 0;
    } else if (a <= L, &&R <= b) {
        tree[v] += x * (R - L + 1);
        tree2[v] += x;
        return tree[v];
    } else {
        push(v, R - L + 1);
        add(a, b, L, (L + R) / 2, 2 * v, x);
        add(a, -b, (L + R), / R + 1, R, 2 * v, x);
        tree[v] = tree[2 * v] + tree[v * 2 + 1];
        return odcz(L) + odcz(R);
    }
}
