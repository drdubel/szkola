#include <iostream>
using namespace std;

long long dzielnice[10'002];
long long znajomi[10'000];

int main() {
    long long dl_odcinka;
    int il_dzielnic, il_znajomych;
    cin >> dl_odcinka >> il_dzielnic >> il_znajomych;

    for (int i = 1; i < il_dzielnic; i += 1) cin >> dzielnice[i];
    dzielnice[0] = 0;
    dzielnice[il_dzielnic] = dl_odcinka;

    for (int j = 0; j < il_znajomych; j += 1) cin >> znajomi[j];

    for (int i = 1; i <= il_dzielnic; i += 1) {
        long long mniejsze = dzielnice[i - 1];
        long long większe = dzielnice[i];
        for (int j = 0; j < il_znajomych; j += 1) {
            if (mniejsze <= znajomi[j] and znajomi[j] <= większe) {
                cout << (j + 1) << ' ';
            }
        }
        cout << '\n';
    }
}
