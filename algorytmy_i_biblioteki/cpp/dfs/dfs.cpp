#include <iostream>
#include <vector>
using namespace std;

const unsigned int MAXN = 1e6 + 7;

vector<unsigned int> polaczenia[MAXN];
bool odwiedzony[MAXN];

void dfs(int k) {
    odwiedzony[k] = 1;
    for (int wierzcholek : polaczenia[k])
        if (!odwiedzony[wierzcholek]) dfs(wierzcholek);
}