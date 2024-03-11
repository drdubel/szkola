from sys import stdin


def main():
    n = int(stdin.readline())
    budynki = [int(stdin.readline().split()[1]) for _ in range(n)]
    zakresy_budynkow = [(0, n)]
    ilosc_plakatow = 0

    while zakresy_budynkow:
        nowe_zakresy_budynkow = []

        for zakres in zakresy_budynkow:
            ilosc_plakatow += 1
            grupa_budynkow = budynki[zakres[0] : zakres[1]]
            najnizszy = min(grupa_budynkow)
            najwyzszy = max(grupa_budynkow)
            indeksy = [
                idx + zakres[0]
                for idx, budynek in enumerate(grupa_budynkow)
                if budynek == najnizszy
            ]
            for i in range(len(grupa_budynkow)):
                budynki[zakres[0] + i] -= najnizszy

            if najwyzszy == najnizszy:
                continue

            for prev_indeks, indeks in zip(
                [zakres[0], *[indeks + 1 for indeks in indeksy]], [*indeksy, zakres[1]]
            ):
                if prev_indeks != indeks:
                    nowe_zakresy_budynkow.append((prev_indeks, indeks))

        zakresy_budynkow = nowe_zakresy_budynkow

    print(ilosc_plakatow)


if __name__ == "__main__":
    main()
