import os
import random
import sys

from tqdm import tqdm


def gen(N):
    for i in tqdm(range(N)):
        payload = ""

        t = random.randint(1, 10)
        payload += f"{t}\n"

        for _ in range(t):
            n = random.randint(1, 20)
            a = random.randint(0, 100)
            b = random.randint(0, 100)

            payload += f"{n} {a} {b}\n"
            payload += " ".join(map(str, sorted(random.sample(range(1, 1000), n)))) + "\n"

        with open(f"in/test{i+1:03d}.in", "w") as f:
            f.writelines(payload)

        os.system(f"python brut.py < in/test{i+1:03d}.in > out/test{i+1:03d}.out")


def main():
    N = int(sys.argv[1])

    gen(N)


if __name__ == "__main__":
    main()
