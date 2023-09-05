#include <iostream>
#include <map>

using namespace std;

int w, i;
string k, p, rk, rp;
map<string, map<string, int>> sedzia = {
    {"8<", {{"8<", 0}, {"()", 1}, {"[]", -1}}},
    {"()", {{"8<", -1}, {"()", 0}, {"[]", 1}}},
    {"[]", {{"8<", 1}, {"()", -1}, {"[]", 0}}}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> p >> k;
    for (; i < k.length(); i += 2) {
        rk = k[i];
        rk += k[i + 1];
        rp = p[i];
        rp += p[i + 1];
        w += sedzia[rk][rp];
    }
    if (w < 0)
        cout << "PRZEGRANA\n";
    else if (w == 0)
        cout << "REMIS\n";
    else if (w > 0)
        cout << "WYGRANA\n";
}
