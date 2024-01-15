def solve(n, d):
    for s in range(105):
        if (d + 1) ** s >= n:
            print(s)
            return
      
t = int(input())
for _ in range(t):
    solve(*tuple(map(int, input().split())))
