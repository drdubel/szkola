#include <iostream>

using namespace std;

typedef pair<long long, long long> pllll;

pllll p1, p2, p3, p4;
int segNum, i;

bool onSegment(pllll p, pllll q, pllll r) {
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) &&
        q.second >= min(p.second, r.second))
        return true;

    return false;
}

int orientation(pllll p, pllll q, pllll r) {
    long long val = (q.second - p.second) * (r.first - q.first) -
                    (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect(pllll p1, pllll p2, pllll p3, pllll p4) {
    int o1 = orientation(p1, p2, p3);
    int o2 = orientation(p1, p2, p4);
    int o3 = orientation(p3, p4, p1);
    int o4 = orientation(p3, p4, p2);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p3, p2)) return true;
    if (o2 == 0 && onSegment(p1, p4, p2)) return true;
    if (o3 == 0 && onSegment(p3, p1, p4)) return true;
    if (o4 == 0 && onSegment(p3, p2, p4)) return true;

    return false;
}

int main() {
    scanf("%d", &segNum);
    for (i = 0; i < segNum; ++i) {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &p1.first, &p1.second,
              &p2.first, &p2.second, &p3.first, &p3.second, &p4.first,
              &p4.second);
        doIntersect(p1, p2, p3, p4) ? printf("TAK\n") : printf("NIE\n");
    }
}
