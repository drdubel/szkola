import os
from random import choice, randint


def gen():
    n = randint(3, 10000)
    k = randint(2, n)
    rzuty = "".join(choice("O" * (n - 1) + "R") for _ in range(n))

    return f"{n} {k}\n{rzuty}"


def main():
    for i in range(2000):
        with open(f"in/{i:02}.in", "w") as f:
            f.write(gen() + "\n")

        os.system(f"./brut < in/{i:02}.in > out/{i:02}.out")


if __name__ == "__main__":
    main()
