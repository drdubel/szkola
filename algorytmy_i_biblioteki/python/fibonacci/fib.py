import time


def fib(ktora):
    liczba1 = 0
    liczba2 = 1
    for _ in range(ktora):
        liczba1, liczba2 = liczba2, liczba1 + liczba2
    return liczba2


def main():
    liczba = int(input())
    print(fib(liczba))


if __name__ == "__main__":
    main()
