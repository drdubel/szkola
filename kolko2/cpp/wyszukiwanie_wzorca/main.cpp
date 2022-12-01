#include <bits/stdc++.h>

using namespace std;

int maxOverlap(string S, string T) {
    string str = T;
    int count[T.length()] = {0};
    int overlap = 0;
    int max_overlap = 0;

    for (int i = 0; i <= S.length(); i++) {
        int index = str.find(S[i]);

        if (index == 0) {
            overlap++;

            if (overlap >= 2) max_overlap = max(overlap, max_overlap);

            count[index]++;
        } else {
            if (count[index - 1] <= 0) return -1;

            count[index]++;
            count[index - 1]--;
        }

        if (index == 4) overlap--;
    }

    if (overlap == 0)
        return max_overlap;
    else
        return -1;
}

int main() {
    string S;
    string T;
    cin >> T >> S;
    cout << maxOverlap(S, T) << "\n";
}