def cukiernia(il_przed, maks_suma_wag, waga, wartosc):
    tablica_wynikow = [
        [0 for i in range(maks_suma_wag + 1)] for j in range(il_przed + 1)
    ]
    for i in range(1, il_przed + 1):
        p = i - 1
        for j in range(1, maks_suma_wag + 1):
            if waga[p] <= j:
                tablica_wynikow[i][j] = max(
                    wartosc[p] + tablica_wynikow[p][j -
                                                    waga[p]], tablica_wynikow[p][j]
                )
            else:
                tablica_wynikow[i][j] = tablica_wynikow[p][j]
    return tablica_wynikow[il_przed][maks_suma_wag]


def main():
    il_przed, maks_suma_wag = list(map(int, input().split()))
    waga = []
    wartosc = []
    for i in range(il_przed):
        wejsc = input().split()
        waga.append(int(wejsc[0]))
        wartosc.append(int(wejsc[1]))
    print(cukiernia(il_przed, maks_suma_wag, waga, wartosc))


if __name__ == "__main__":
    main()
