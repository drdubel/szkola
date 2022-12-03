def main():
    il_murow, szer_wawozu = list(map(int, input().split()))
    wawoz = [0 for _ in range(szer_wawozu)]
    strona = 1
    for _ in range(il_murow):
        szer_muru = (int(input())) * strona
        for i in range(szer_muru * strona):
            if strona > 0:
                wawoz[i] += 1
            else:
                wawoz[szer_wawozu - i - 1] += 1
        strona *= -1
    najmniej_murow = min(wawoz)
    print(najmniej_murow, wawoz.count(najmniej_murow))


if __name__ == "__main__":
    main()
