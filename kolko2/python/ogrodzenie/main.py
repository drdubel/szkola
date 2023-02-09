from math import sqrt, atan2, pi


def orientation(p1, p2, p3):
    val = (p2[1] - p1[1]) * (p3[0] - p2[0]) - (p2[0] - p1[0]) * (p3[1] - p2[1])
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return 2


def grahamScan(graph, n):
    border = [0, 1]
    p = 0
    c = 1
    for n in range(2, n):
        if orientation(graph[p], graph[c], graph[n]) != 2:
            border.pop()
        border.append(n)
        c = border[-1]
        p = border[-2]
    border.append(0)
    return sum(
        [
            sqrt(
                (graph[border[i]][0] - graph[border[i - 1]][0]) ** 2
                + (graph[border[i]][1] - graph[border[i - 1]][1]) ** 2
            )
            for i in range(1, len(border))
        ]
    )


def main():
    n = int(input())
    graph = sorted(
        [list(map(int, input().split())) for _ in range(n)], key=lambda p: (p[1], p[0])
    )
    graph = [graph[0]] + sorted(
        graph[1:],
        key=lambda p: (
            atan2(p[1] - graph[0][1], p[0] - graph[0][0]) * 180 / pi % 360,
            sqrt((p[0] - graph[0][0]) ** 2 + (p[1] - graph[0][1]) ** 2),
        ),
    )
    borderLen = grahamScan(graph, n)
    print(borderLen)


if __name__ == "__main__":
    main()
