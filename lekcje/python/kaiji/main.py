import re

wyg = {"8<": "()", "()": "[]", "[]": "8<"}


def sedzia(k, p):
    wyn = 0
    for rk, rp in zip(k, p):
        if wyg[rk] == rp:
            wyn += 1
        elif rk != rp:
            wyn -= 1
    if wyn < 0:
        return "PRZEGRANA"
    if wyn == 0:
        return "REMIS"
    if wyn > 0:
        return "WYGRANA"


def main():
    k = re.findall("..", input())
    p = re.findall("..", input())
    print(sedzia(k, p))


if __name__ == "__main__":
    main()
