import os
import random
import sys


def gen(N):
    for i in range(N):
        payload = ""

        n = random.randint(2, 1000)
        t = random.randint(2, 1000)
        payload += f"{n} {t}\n"

        stacje = random.sample(list(zip(*(range(-20000, 20000), range(-20000, 20000)))), n)
        payload += "\n".join([" ".join(map(str, x)) for x in stacje]) + "\n"

        znajomi = [random.sample(range(1, n), 2) for _ in range(t)]
        payload += "\n".join([" ".join(map(str, x)) for x in znajomi]) + "\n"

        with open(f"in/test{i+1:03d}.in", "w") as f:
            f.writelines(payload)

        os.system(f"./brut < in/test{i+1:03d}.in > out/test{i+1:03d}.out")


def main():
    N = int(sys.argv[1])

    os.system("g++ -g -o brut brut.cpp")

    gen(N)


if __name__ == "__main__":
    main()
