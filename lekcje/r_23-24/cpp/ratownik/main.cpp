#include <cmath>
#include <iostream>

using namespace std;

struct Pos {
    int x, y;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, range, notPossible = 0;
    double dist;
    Pos rescPos, childPos;

    cin >> n >> range >> rescPos.x >> rescPos.y;

    for (int i = 0; i < n; ++i) {
        cin >> childPos.x >> childPos.y;
        dist = sqrt(pow(abs(childPos.x - rescPos.x), 2) +
                    pow(abs(childPos.y - rescPos.y), 2));

        if (dist > range) notPossible++;
    }
    cout << notPossible << "\n";
}