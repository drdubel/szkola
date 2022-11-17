def topologicalSortUtil(v):
    global Stack, visited, adj
    visited[v] = True

    for i in adj[v]:
        if not visited[i[0]]:
            topologicalSortUtil(i[0])

    Stack.append(v)


def longestPath(s):
    global Stack, visited, adj, il_odnog
    dist = [-(10**9) for i in range(il_odnog)]

    for i in range(il_odnog):
        if visited[i] == False:
            topologicalSortUtil(i)

    dist[s] = 0

    while len(Stack) > 0:

        u = Stack[-1]
        del Stack[-1]

        if dist[u] != 10**9:
            for i in adj[u]:
                if dist[i[0]] < dist[u] + i[1]:
                    dist[i[0]] = dist[u] + i[1]

    for i in range(il_odnog):
        print("INF ", end="") if (dist[i] == -(10**9)) else print(dist[i], end=" ")


def main():
    il_odnog = int(input())
    il_ryb = {i: koszt for i, koszt in enumerate(list(map(int, input().split())))}
    rzeka = {i: [] for i in range(1, il_odnog + 1)}
    for _ in range(il_odnog - 1):
        od, do = list(map(int, input().split()))
        rzeka[od].append(do)
    Stack, visited = [], [False for i in range(il_odnog + 1)]
    adj = [[] for i in range(7)]

    s = 1
    print("Following are longest distances from source vertex ", s)
    longestPath(s)


if __name__ == "__main__":
    il_odnog = int(input())
    il_ryb = {i: koszt for i, koszt in enumerate(list(map(int, input().split())))}
    rzeka = {i: [] for i in range(1, il_odnog + 1)}
    for _ in range(il_odnog - 1):
        od, do = list(map(int, input().split()))
        rzeka[od].append(do)
    Stack, visited = [], [False for i in range(il_odnog + 1)]
    adj = [[] for i in range(7)]

    s = 1
    print("Following are longest distances from source vertex ", s)
    longestPath(s)
