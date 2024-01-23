def get_change_making_matrix(set_of_coins, r: int):
    m = [[0 for _ in range(r + 1)] for _ in range(len(set_of_coins) + 1)]
    for i in range(1, r + 1):
        m[0][i] = float("inf")
    return m


def change_making(coins, n: int):
    """This function assumes that all coins are available infinitely.
    n is the number to obtain with the fewest coins.
    coins is a list or tuple with the available denominations.
    """
    m = get_change_making_matrix(coins, n)
    for c, coin in enumerate(coins, 1):
        for r in range(1, n + 1):
            # Just use the coin
            if coin == r:
                m[c][r] = 1
            elif coin > r:
                m[c][r] = m[c - 1][r]
            else:
                m[c][r] = min(m[c - 1][r], 1 + m[c][r - coin])
    return m[-1][-1]


def main():
    il_monet, reszta = list(map(int, input().split()))
    monety = list(map(int, input().split()))
    wynik = change_making(monety, reszta)
    if wynik == float("inf"):
        print("NIE")
    else:
        print(wynik)


if __name__ == "__main__":
    main()
