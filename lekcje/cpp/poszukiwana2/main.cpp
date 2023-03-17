#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 7;
int n, q, k, liczba;

int main() {
    scanf("%d%d", &n, &q);
    pair<int, int> liczby[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &liczby[i].first);
        liczby[i].second = i + 1;
    }
    sort(liczby, liczby + n);
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        if (k > liczby[n - 1].first) {
            printf("AAAAAAAAAAAAAAAAAA!11!!1!!\n");
            continue;
        }
        auto gk = lower_bound(liczby, liczby + n, make_pair(k, 0));
        printf("%d\n", liczby[gk - liczby].second);
    }
}