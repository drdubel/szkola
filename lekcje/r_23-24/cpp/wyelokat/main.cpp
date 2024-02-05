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
    int n;
    scanf("%d", &n);
    Point polygon[n + 1];

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &polygon[i].x, &polygon[i].y);
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
