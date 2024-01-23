#include <cmath>
#include <iostream>

using namespace std;

struct Point {
    long long x, y;
};

bool onSegment(Point a, Point b, Point c) {
    if (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) &&
        b.y >= min(a.y, c.y))
        return true;

    return false;
}

long long orientation(Point a, Point b, Point c) {
    long long val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool isIntersecting(Point a, Point b, Point c, Point d) {
    long long o1 = orientation(a, b, c);
    long long o2 = orientation(a, b, d);
    long long o3 = orientation(c, d, a);
    long long o4 = orientation(c, d, b);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(a, c, b)) return true;
    if (o2 == 0 && onSegment(a, d, b)) return true;
    if (o3 == 0 && onSegment(c, a, d)) return true;
    if (o4 == 0 && onSegment(c, b, d)) return true;

    return false;
}

int main() {
    long long n;
    Point a, b, c, d;

    scanf("%lld", &n);

    for (long long i = 0; i < n; ++i) {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y, &c.x,
              &c.y, &d.x, &d.y);
        printf("%s\n", isIntersecting(a, b, c, d) ? "TAK" : "NIE");
    }
}