import re
import sys


def main():
    a = sys.stdin.readline()[:-1]
    b = sys.stdin.readline()[:-1]
    print(len(re.findall(f"(?=({a}))", b)))


if __name__ == "__main__":
    main()
