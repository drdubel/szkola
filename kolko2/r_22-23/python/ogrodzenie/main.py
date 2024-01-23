from math import sqrt, atan2, pi


def orientation(p1, p2, p3):
    return ((p2[1] - p1[1]) * (p3[0] - p2[0]) - (p2[0] - p1[0]) * (p3[1] - p2[1])) >= 0


def grahamScan(points, n):
    border = [0, 1]
    p = 0
    c = 1
    for next in range(2, n):
        if orientation(points[p], points[c], points[next]):
            border.pop()
        border.append(next)
        c = border[-1]
        p = border[-2]
    border.append(0)
    return sum(
        [
            sqrt(
                (points[border[i]][0] - points[border[i - 1]][0]) ** 2
                + (points[border[i]][1] - points[border[i - 1]][1]) ** 2
            )
            for i in range(1, len(border))
        ]
    )


def main():
    n = int(input())
    points = sorted(
        [list(map(int, input().split())) for _ in range(n)], key=lambda p: (p[1], p[0])
    )
    points = [points[0]] + sorted(
        points[1:],
        key=lambda p: (
            atan2(p[1] - points[0][1], p[0] - points[0][0]) * 180 / pi,
            sqrt((p[0] - points[0][0]) ** 2 + (p[1] - points[0][1]) ** 2),
        ),
    )
    borderLen = grahamScan(points, n)
    print("0.%10g" % borderLen)


if __name__ == "__main__":
    main()
