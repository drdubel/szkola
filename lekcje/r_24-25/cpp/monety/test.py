import os


def test(i):
    os.system(f"./main < in/{i:02}.in > moje.out")
    with open("moje.out") as moje, open(f"out/{i:02}.out") as wzor:
        if moje.read() != wzor.read():
            print(f"Test {i} nie zaliczony")
            return False
        else:
            print(f"Test {i} zaliczony")
            return True


def main():
    for i in range(2000):
        if not test(i):
            return

    print("Zaliczono wszystkie testy")


if __name__ == "__main__":
    main()
