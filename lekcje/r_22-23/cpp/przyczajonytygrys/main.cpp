#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
int smoki[MAXN], tygrysy[MAXN], n, q, i, pole, od_ilu, do_ilu;

int main() {
    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) {
        scanf("%d", &pole);
        smoki[i] = smoki[i - 1];
        tygrysy[i] = tygrysy[i - 1];
        if (pole == 3)
            tygrysy[i]++;
        else if (pole == 4)
            smoki[i]++;
    }
    for (i = 0; i < q; i++) {
        scanf("%d%d", &od_ilu, &do_ilu);
        printf("%d %d\n", tygrysy[do_ilu] - tygrysy[od_ilu - 1],
               smoki[do_ilu] - smoki[od_ilu - 1]);
    }
}
