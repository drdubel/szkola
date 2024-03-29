import re
import sys


def czy_palindrom(slowo):
    if slowo.upper() == slowo.upper()[::-1]:
        return True
    return False


def main(indata):
    _ = int(next(indata))
    kolejnosc_danych = list(map(int, next(indata).split()))
    tekst = next(indata)
    dane = []
    for nr_danych in kolejnosc_danych:
        if nr_danych == 1:
            dane.append(len(re.findall(r" ", tekst)))
        elif nr_danych == 2:
            dane.append(len(re.findall(r"[0-9]+", tekst)))
        elif nr_danych == 3:
            dane.append(len(re.findall(r"[a-zA-Z]+", tekst)))
        elif nr_danych == 4:
            dane.append(len(re.findall(r"([^.]*[a-zA-Z]+[^.]*\.)", tekst)))
        elif nr_danych == 5:
            dane.append(
                sum(
                    [
                        1 if slowo.upper() == slowo.upper()[::-1] else 0
                        for slowo in re.findall(r"[a-zA-Z]+", tekst)
                    ]
                )
            )
    return [" ".join(list(map(str, dane)))]


def run():
    for line in main((line.rstrip() for line in sys.stdin)):
        print(line)


if __name__ == "__main__":
    run()
