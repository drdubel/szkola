#include <iostream>

using namespace std;

const unsigned int MAXN = 1e6 + 7;

int rodzic[MAXN], ranga[MAXN], a, b;

int Find(int x) {
    if (rodzic[x] != x) rodzic[x] = Find(rodzic[x]);
    return rodzic[x];
}

void Union(int x, int y) {
    a = Find(x);
    b = Find(y);
    if (ranga[a] < ranga[b])
        rodzic[a] = b;
    else
        rodzic[b] = a;
