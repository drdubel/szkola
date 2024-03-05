from sys import stdin


def knapsack(capacity, items, n):
    dp = [0 for _ in range(capacity + 1)]

    for i in range(1, n + 1):
        for w in range(capacity, 0, -1):
            if items[i - 1] <= w:
                dp[w] = max(dp[w], dp[w - items[i - 1]] + items[i - 1])

    return dp[capacity]


def main():
    n = int(stdin.readline().strip())
    items = sorted(map(int, stdin.readline().strip().split()))

    biggest = items.pop()
    total_sum = sum(items)
    capacity = total_sum // 2
    can_fit = knapsack(capacity, items, n - 1)
    time = can_fit + biggest

    print(time)


if __name__ == "__main__":
    main()
