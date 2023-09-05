#include <algorithm>
#include <iostream>
using namespace std;

string k, l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> l;
    sort(k.begin(), k.end());
    sort(l.begin(), l.end());
    if (k == l)
        cout << "TAK\n";
    else
        cout << "NIE\n";

    return 0;
}