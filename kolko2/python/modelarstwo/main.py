import sys


def silnia(n, mod):
    out = 1
    for i in range(1, n + 1):
        out = (out * i) % mod
    return out


def fpow(b, exp, m):
    res = 1
    while exp > 1:
        if exp & 1:
            res = (res * b) % m
        b = b**2 % m
        exp >>= 1
    return (b * res) % m


def main():
    [n, m, mod] = list(map(int, sys.stdin.readline().split()))

    print(
        silnia(n + m, mod)
        * fpow(silnia(n, mod) * silnia(m, mod) % mod, mod - 2, mod)
        % mod
    )


if __name__ == "__main__":
    main()
