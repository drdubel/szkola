from math import log2, floor


def main():
    il_ciec = int(input())
    print(2 ** (floor(log2(il_ciec)) + 1))


if __name__ == "__main__":
    main()
