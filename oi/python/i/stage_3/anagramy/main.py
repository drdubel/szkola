import numpy as np


def main():
    n = int(input())
    x = np.unique([input() for _ in range(n)])
    a = {}
    for word in x:
        sword = "".join(sorted(word))
        if sword not in a:
            a[sword] = [word]
        else:
            a[sword].append(word)
    for words in a.values():
        print(" ".join(words))


if __name__ == "__main__":
    main()
