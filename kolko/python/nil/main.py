def drogosprawdzacz(il_ryb, rzeka):
    maks_zlapane_ryby = il_ryb[1]
    zlapane_ryby = il_ryb[1]
    
    return maks_zlapane_ryby


def czy_koniec(il_ryb, rzeka, odnoga):
    if rzeka[odnoga]:
        czy_koniec(il_ryb, rzeka, odnoga)


def main():
    il_odnog = int(input())
    il_ryb = {i: koszt for i, koszt in enumerate(list(map(int, input().split())))}
    rzeka = {i: [] for i in range(1, il_odnog + 1)}
    for _ in range(il_odnog - 1):
        od, do = list(map(int, input().split()))
        rzeka[od].append(do)
    print(drogosprawdzacz(il_ryb, rzeka))


main()
