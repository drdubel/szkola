import os
import random
import sys


def gen(N):
    for i in range(N):
        payload = ""

        n = random.randint(3, 5)
        payload += f"{n}\n"

        for _ in range(n):
            payload += f"{random.randint(0, 10)} {random.randint(0, 10)} {random.randint(0, 10)}\n"

        with open(f"in/test{i+1:03d}.in", "w") as f:
            f.writelines(payload)

        os.system(f"./wzor < in/test{i+1:03d}.in > out/test{i+1:03d}.out")


def main():
    N = int(sys.argv[1])

    os.system("g++ -g -o wzor wzor.cpp")

    gen(N)


if __name__ == "__main__":
    main()
