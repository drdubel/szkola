#include <iostream>

using namespace std;

typedef pair<int, int> pii;

pii p1, p2, p3, p4;
int segNum, i;

bool onSegment(pii p, pii q, pii r) {
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) &&
        q.second >= min(p.second, r.second))
        return true;

    return false;
}

int orientation(pii p, pii q, pii r) {
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect(pii p1, pii p2, pii p3, pii p4) {
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> segNum;
    for (i = 0; i < segNum; ++i) {
        cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >>
            p3.second >> p4.first >> p4.second;
        doIntersect(p1, p2, p3, p4) ? cout << "TAK\n" : cout << "NIE\n";
    }
}
