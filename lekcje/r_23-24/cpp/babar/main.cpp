#include <iostream>
#include <vector>

using namespace std;

pair<int, string> znajdzPodciag(string& slowo1, string& slowo2) {
    int n = slowo1.size();
    int m = slowo2.size();
    string podciag;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (size_t i = 1; i < n; i++) {
        for (size_t j = 1; j < m; j++) {
            if (slowo1[i] == slowo2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n - 1;
    int j = m - 1;

    while (dp[i][j] != 0)
        if (slowo1[i] == slowo2[j]) {
            podciag = slowo1[i] + podciag;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;

    return {dp[n - 1][m - 1], podciag};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string slowo1, slowo2;
    pair<int, string> podciag;

    cin >> slowo1 >> slowo2;

    slowo1 = " " + slowo1;
    slowo2 = " " + slowo2;

    podciag = znajdzPodciag(slowo1, slowo2);
    cout << podciag.first << "\n" << podciag.second << "\n";
}