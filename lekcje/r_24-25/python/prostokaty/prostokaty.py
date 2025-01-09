def minMaxProstokaty(prostokaty: list[list[int]]) -> tuple[int, int]:
    minn = 1e9
    maxx = 0

    for prostokat in prostokaty:
        minn = min(minn, prostokat[0] * prostokat[1])
        maxx = max(maxx, prostokat[0] * prostokat[1])

    return minn, maxx


def zmiescProstokaty(prostokaty: list[list[int]]) -> tuple[int, int, int]:
    maxn = 1
    n = 1
    max_prostokat = prostokaty[0]
    pop_prostokat = prostokaty[0]

    for prostokat in prostokaty[1:]:
        if prostokat[0] <= pop_prostokat[0] and prostokat[1] <= pop_prostokat[1]:
            n += 1
        else:
            if n > maxn:
                maxn = n
                max_prostokat = pop_prostokat

            n = 1

        pop_prostokat = prostokat

    return maxn, *max_prostokat


def maxSzerokosci(prostokaty: list[list[int]]) -> tuple[int, int]:
    takie_same: dict[int, list[int]] = {}

    max2 = 0
    max3 = 0
    max5 = 0

    for prostokat in prostokaty:
        if prostokat[0] not in takie_same:
            takie_same[prostokat[0]] = [prostokat[1]]

        else:
            takie_same[prostokat[0]].append(prostokat[1])

    for wysokosc in takie_same:
        takie_same[wysokosc].sort(reverse=True)

        max2 = max(max2, sum(takie_same[wysokosc][:2]))
        max3 = max(max3, sum(takie_same[wysokosc][:3]))
        max5 = max(max5, sum(takie_same[wysokosc][:5]))

    return max2, max3, max5


def main():
    with open("prostokaty.txt", "r") as f:
        prostokaty = [tuple(map(int, x.split())) for x in f.read().strip().split("\n")]

        minn, maxx = minMaxProstokaty(prostokaty)
        n, a, b = zmiescProstokaty(prostokaty)
        max2, max3, max5 = maxSzerokosci(prostokaty)

        print(minn, maxx, "\n")
        print(n, a, b, "\n")
        print(max2, max3, max5)

    with open("wyniki4.txt", "w") as f:
        f.write(f"4.1 {minn} {maxx}\n")
        f.write(f"4.2 {n} {a} {b}\n")
        f.write(f"4.3 {max2} {max3} {max5}")


if __name__ == "__main__":
    main()
