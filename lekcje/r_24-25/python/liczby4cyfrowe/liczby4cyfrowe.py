def pierwsza(x):
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True


def il_dziel_pier(x):
    n = 0

    for i in range(2, int(x**0.5) + 1):
        if x % i == 0 and pierwsza(i):
            n += 1

    return n


def roznica(x):
    x2 = abs(int("".join(sorted(str(x)))) - int("".join(sorted(str(x), reverse=True))))
    if x2 < x:
        return -1
    elif x2 == x:
        return 0
    return 1


with open("liczby.txt", "r") as f0:
    f = list(map(int, f0.read().split()))
    n = 0

    for x in f:
        if x**0.5 % 1 < 10**-5:
            if n == 0:
                print(x)
            n += 1
    print(n)
    print("")

    for x in f:
        if il_dziel_pier(x) >= 5:
            print(x)
    print("")

    mniejsza = 0
    rowna = 0
    wieksza = 0

    for x in f:
        res = roznica(x)
        if res == -1:
            mniejsza += 1
        elif res == 0:
            rowna += 1
        else:
            wieksza += 1

    print(mniejsza)
    print(rowna)
    print(wieksza)
