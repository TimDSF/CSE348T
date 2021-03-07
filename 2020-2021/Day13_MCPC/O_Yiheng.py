# Credit: Yiheng Yao
import math

def sol():
    k, r = list(map(int, input().split()))
    ingredients = list(map(int, input().split()))
    result = 0
    for i in range(r):
        line = list(map(int, input().split()))
        revenue = line[-1]
        amt = None
        for j in range(k):
            if (amt is not None and line[j] != 0):
                amt = min(amt,ingredients[j]//line[j])
            elif (amt is None and line[j] != 0):
                amt = ingredients[j]//line[j]
        result = max(result, amt*revenue)
    return result

print(sol())