#include <cmath>
#include <iostream>

using namespace std;

int k, p, p_sum, i;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for (i = 0; i <= k; i++) {
        cin >> p;
        p_sum += p * pow(2, i);
    }
    cout << p_sum + 1;
}
