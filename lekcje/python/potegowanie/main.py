def main():
    n = int(input())
    for _ in range(n):
        a, b = map(int, input().split())
        print(pow(a, b, 10000007))


if __name__ == "__main__":
    main()
