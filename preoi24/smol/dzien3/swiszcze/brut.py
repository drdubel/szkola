def main():
    n = int(input())
    swiszcze = sorted([list(map(int, input().split())) for _ in range(n)])[::-1]

    def ile_grup(najmlodszy=2e9, i=0, il_grup=0):
        if i == n:
            return il_grup

        il_grup1 = 2e9

        if swiszcze[i][0] >= najmlodszy:
            il_grup1 = ile_grup(najmlodszy, i + 1, il_grup)

        il_grup = min(ile_grup(swiszcze[i][0] / swiszcze[i][1], i + 1, il_grup + 1), il_grup1)

        return il_grup

    print(ile_grup())


if __name__ == "__main__":
    main()
