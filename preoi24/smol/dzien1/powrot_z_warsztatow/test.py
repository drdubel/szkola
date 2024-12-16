import os


def test():
    for file in sorted(os.listdir("in")):
        file = file.split(".")[0]

        os.system(f"./main < in/{file}.in > moje.out")

        if os.popen(f"diff moje.out out/{file}.out").read():
            print(f"Test {file} failed")

            break


def main():
    os.system("g++ -g -o main main.cpp")

    test()


if __name__ == "__main__":
    main()
