def fib(n):
    liczby = [1, 1]

    while liczby[-1] <= n:
        liczby.append(liczby[-2] + liczby[-1])

    return liczby


def najmniejsza_plansza(liczby, m, depth=0):
    if m == 1:
        return depth - 1

    n = 1e18

    for l in liczby[2:]:
        if m % l == 0:
            n = min(najmniejsza_plansza(liczby, m // l, depth + 1) + liczby.index(l), n)

    return n


def main():
    liczby = fib(1e18)

    m = int(input())

    n = najmniejsza_plansza(liczby, m)

    if n == 1e18:
        print("NIE")

    else:
        print(n)


if __name__ == "__main__":
    main()
