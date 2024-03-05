from sys import stdin


def rozdystrybuuj_drewno(drewno):
    list1 = []
    list2 = []
    suma1 = 0
    suma2 = 0

    for pieniek in drewno:
        if suma1 <= suma2:
            list1.append(pieniek)
            suma1 += pieniek
        else:
            list2.append(pieniek)
            suma2 += pieniek

    return suma1, suma2


def main():
    n = int(stdin.readline().strip())
    drewno = sorted(map(int, stdin.readline().split()))
    najdluzszy_pieniek = drewno.pop()
    bajtek, bitek = rozdystrybuuj_drewno(drewno[::-1])
    print(min(bajtek, bitek) + najdluzszy_pieniek)


if __name__ == "__main__":
    main()
