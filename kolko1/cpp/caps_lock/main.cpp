#include <iostream>
#include <unordered_map>

using namespace std;

long long policz_podciagi(string& slowo, int N) {
    unordered_map<int, int> pop_suma;
    long long il_podciagow = 0;
    int akt_suma = 0;
    for (int i = 0; i < N; i++) {
        if ((slowo[i] >= 'A') & (slowo[i] <= 'Z')) {
            akt_suma++;
        } else
            akt_suma--;
        if (akt_suma == 0) il_podciagow++;
        if (pop_suma.find(akt_suma) != pop_suma.end()) {
            il_podciagow += (pop_suma[akt_suma]);
        }
        pop_suma[akt_suma]++;
    }
    return il_podciagow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string slowo;
    cin >> slowo;
    cout << policz_podciagi(slowo, slowo.length());
}