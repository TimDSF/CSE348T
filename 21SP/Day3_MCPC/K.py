# Credit: Yiheng Yao
import sys
import math

def sol():
    n = int(input())
    line = input()
    k = 0
    for i in range(1,n+1):
        s = str(i)
        s_len = len(s)
        if (line[k:k+s_len] != s):
            return i
        k += s_len

print(sol())
