# credit: Yiheng Yao

import sys
from collections import defaultdict

def sol():
    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    N = int(input())
    dictionary = defaultdict(int)
    for n in range(N):
        w = input()
        dictionary[w[0]+w[-1]] += 1
    result = 0
    for tl in alpha:
        for tr in alpha:
            for bl in alpha:
                for br in alpha:
                    corners = defaultdict(int)
                    corners[tl+tr] += 1
                    corners[tl+bl] += 1
                    corners[tr+br] += 1
                    corners[bl+br] += 1
                    val = 1
                    for key, num in corners.items():
                        for i in range(num):
                            val *= dictionary[key]-i
                    result += val
    return result

print(sol())