MOD = 1000000007


def fastDoubling(n, res):
    if n == 0:
        res[0] = 0
        res[1] = 1
        return

    fastDoubling((n // 2), res)
    a = res[0]
    b = res[1]

    c = 2 * b - a

    if c < 0:
        c += MOD
    c = (a * c) % MOD
    d = (a * a + b * b) % MOD
    if n % 2 == 0:
        res[0] = c
        res[1] = d
    else:
        res[0] = d
        res[1] = c + d


def main():
    res = [0] * 2
    fastDoubling(int(input()), res)
    print(res[0])


if __name__ == "__main__":
    main()
