MOD = 123456789


def szypszyppot(n, wyn):
    if n == 0:
        wyn[0] = 0
        wyn[1] = 1
        return

    szypszyppot((n // 2), wyn)
    a = wyn[0]
    b = wyn[1]

    c = 2 * b - a

    if c < 0:
        c += MOD
    c = (a * c) % MOD
    d = (a * a + b * b) % MOD
    if n % 2 == 0:
        wyn[0] = c
        wyn[1] = d
    else:
        wyn[0] = d
        wyn[1] = c + d


def main():
    wyn = [0] * 2
    szypszyppot(int(input()), wyn)
    print(wyn[0])


if __name__ == "__main__":
    main()
