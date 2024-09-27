import os

from gen import gen


def test(i):
    with open("test.in", "w") as f:
        f.write(gen() + "\n")
    os.system("./main < test.in > moje.out")
    os.system("./brut < test.in > wzor.out")
    with open("moje.out") as moje, open("wzor.out") as wzor:
        if moje.read() != wzor.read():
            print(f"Test {i} nie zaliczony")
            return False
        else:
            print(f"Test {i} zaliczony")
            return True


def main():
    i = 0
    while True:
        if not test(i):
            return

        i += 1


if __name__ == "__main__":
    main()
