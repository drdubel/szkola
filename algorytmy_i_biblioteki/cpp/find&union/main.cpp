#include <iostream>

using namespace std;

constexpr int maxn = 1000007;
int ojc[maxn];

int Find(int v) {
    if (v == ojc[v])
        return v;
    else {
        ojc[v] = Find(ojc[v]);
        return ojc[v];
    }
}

void Union(int a, int b) {
    Find(a);
    Find(b);
    ojc[ojc[a]] = ojc[b];
}

int main() {}