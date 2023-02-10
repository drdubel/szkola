#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct point {
    int x, y;
};

const int MAXN = 5e5 + 7;
int lowest, n, i;
long double borderLen;
vector<int> border;
point points[MAXN];

bool orientation(point p1, point p2, point p3) {
    return ((p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y)) >= 0;
}

bool porownajKat(point a, point b) {
    long double angleA =
        atan2(a.y - points[0].y, a.x - points[0].x) * 180 / M_PI;
    long double angleB =
        atan2(b.y - points[0].y, b.x - points[0].x) * 180 / M_PI;
    if (angleA == angleB) {
        long double distA =
            sqrt(pow(a.x - points[0].x, 2) + pow(a.y - points[0].y, 2));
        long double distB =
            sqrt(pow(b.x - points[0].x, 2) + pow(b.y - points[0].y, 2));
        return distA < distB;
    }
    return angleA < angleB;
}

void countBorderLen() {
    int prev = 0, curr = 1;
    border.push_back(0);
    border.push_back(1);
    for (int next = 2; next < n; ++next) {
        if (orientation(points[prev], points[curr], points[next])) {
            border.pop_back();
        }
        prev = border[border.size() - 1];
        border.push_back(next);
        curr = border[border.size() - 1];
    }
    border.push_back(0);
    for (i = 0; i < border.size(); ++i) {
        borderLen +=
            sqrt(pow((points[border[i]].x - points[border[i - 1]].x), 2) +
                 pow((points[border[i]].y - points[border[i - 1]].y), 2));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        if ((points[i].y < points[lowest].y) ||
            ((points[i].y == points[lowest].y) &&
             (points[i].x < points[lowest].x)))
            lowest = i;
    }
    swap(points[lowest], points[0]);
    sort(points + 1, points + n, porownajKat);
    countBorderLen();
    cout << fixed << setprecision(10) << borderLen << "\n";
}