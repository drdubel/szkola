import sys

import numpy as np


def main():
    szerokosc_platformy, il_klockow = map(int, sys.stdin.readline().split())
    wysokosci = np.zeros(szerokosc_platformy, dtype=np.int16)
    for _ in range(il_klockow):
        szerokosc_klocka, poczatek_klocka = map(int, sys.stdin.readline().split())
        nowa_wysokosc = (
            max(wysokosci[poczatek_klocka : poczatek_klocka + szerokosc_klocka]) + 1
        )
        for i in range(poczatek_klocka, poczatek_klocka + szerokosc_klocka):
            wysokosci[i] = nowa_wysokosc
    return max(wysokosci)


if __name__ == "__main__":
    print(main())
