krulestwa = []
n = 0
a = 0
b = 0


def podbijaj(stolica, koszt_podboju, i):
    if i == n:
        return koszt_podboju

    koszt_podboju += b * (krulestwa[i] - stolica)
    koszt_podboju = min(
        podbijaj(stolica, koszt_podboju, i + 1),
        podbijaj(krulestwa[i], koszt_podboju + a * (krulestwa[i] - stolica), i + 1),
    )

    return koszt_podboju


def main():
    global krulestwa, n, a, b
    t = int(input())

    for _ in range(t):
        n, a, b = map(int, input().split())
        krulestwa = list(map(int, input().split()))

        print(podbijaj(0, 0, 0))


if __name__ == "__main__":
    main()
