# Credit: Yiheng Yao
from collections import defaultdict

def sol():
    n, m = list(map(int, input().split()))
    last_seen = defaultdict(int)
    accum = 0
    for k in range(m):
        sender = int(input())-1
        accum = accum + (n-1) - (k-last_seen[sender])
        last_seen[sender] = k+1
        print(accum)

sol()