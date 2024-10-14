from sys import stdin


def zmien_genotyp(d, genotyp):
    genotypy = [genotyp]

    for i in range(d):
        nowy_genotyp = genotypy[-1]
        nowy_genotyp = nowy_genotyp[1:] + str(
            int(nowy_genotyp[0]) ^ int(nowy_genotyp[1])
        )
        if nowy_genotyp == genotypy[0]:
            return genotypy[d % i]

        genotypy.append(nowy_genotyp)
    return genotypy[-1]


def main():
    _, d = map(int, stdin.readline().strip().split())
    genotyp = stdin.readline().strip()

    print(zmien_genotyp(d, genotyp))


if __name__ == "__main__":
    main()
