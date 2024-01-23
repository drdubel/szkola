#include <iostream>

using namespace std;

const int INF = 1000 * 1000 * 1000;

struct Point {
    long long x, y;
};

long long polygonArea(const Point *polygon, int n) {
    long long area = 0;

    for (int i = 0; i < n; ++i) {
        area += (polygon[i + 1].x - polygon[i].x) *
                (polygon[i + 1].y + polygon[i].y);
    }

    return area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    Point polygon[n + 1];

    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
        polygon[i].x += INF;
        polygon[i].y += INF;
    }

    polygon[n] = polygon[0];

    long long area = polygonArea(polygon, n);
    if (area % 2 == 0) {
        printf("%lld", (area / 2));
    } else {
        printf("%lld.5", ((area - 1) / 2));
    }
}
