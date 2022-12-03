#include <iostream>
using namespace std;

const int MAXN = 2e6 + 7;
long long arr[MAXN];
long long score, number;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    arr[1000 * 1000] = 1;
    for (auto i : str) {
        if (isupper(i))
            number++;
        else
            number--;
        score += arr[number + 1000 * 1000]++;
    }
    cout << score;

    return 0;
}