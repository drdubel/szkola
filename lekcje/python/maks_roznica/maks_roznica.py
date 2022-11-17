def maks_roznica(ciag_liczb):
    roznica = max(ciag_liczb) - min(ciag_liczb)
    return roznica


def main():
    input()
    ciag_liczb = list(map(int, input().split()))
    print(maks_roznica(ciag_liczb))


if __name__ == "__main__":
    main()
