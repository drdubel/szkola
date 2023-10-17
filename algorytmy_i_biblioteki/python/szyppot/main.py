from sys import stdin


def szyppot(x, n):
    if n == 0:
        return 1
    if n % 2 == 0:
        wynik = szyppot(x, n / 2)
        return (wynik * wynik) % int(1e9 + 7)
    wynik = szyppot(x, n - 1)
    return (wynik * x) % int(1e9 + 7)


def main():
    n = int(stdin.readline().strip())
    for _ in range(n):
        print(szyppot(*map(int, stdin.readline().split())))


if __name__ == "__main__":
    main()
