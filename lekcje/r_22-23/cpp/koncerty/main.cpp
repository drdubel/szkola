#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 7;
long long koncerty[MAXN], il_koncertow, il_planowanych_koncertow,
    wyn = 1e12 + 7, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> il_koncertow >> il_planowanych_koncertow;
    for (i = 1; i <= il_koncertow; ++i) {
        cin >> koncerty[i];
        koncerty[i] += koncerty[i - 1];
    }
    for (i = il_planowanych_koncertow; i <= il_koncertow; ++i) {
        wyn = min(koncerty[i] - koncerty[i - il_planowanych_koncertow], wyn);
    }
    cout << wyn << "\n";
}
