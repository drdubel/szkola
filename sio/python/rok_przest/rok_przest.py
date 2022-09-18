def main():
    a = int(input())
    if a % 100 == 0 and a % 400 == 0 or a % 4 == 0 and a % 100 != 0:
        return "TAK"
    else:
        return "NIE"


if __name__ == "__main__":
    print(main())
