# Credit: Nicholai Dimov
def shoelace(lis):
    s = 0
    for i in range(-1, len(lis)-1):
        s += lis[i][0] * lis[i+1][1]
        s -= lis[i][1] * lis[i+1][0]
    return s / 2

n = int(input())
lis = []
for _ in range(n):
    coords = [int(i) for i in input().split()]
    lis.append(coords)

bigarea = shoelace(lis)
smallarea = 0
for i in range(1, n-1):
    delta = shoelace([lis[0], lis[i], lis[i+1]])
    smallarea += delta
    if smallarea * 2 >= bigarea:
        # this is the triangle
        frac = (smallarea - bigarea / 2)/delta
        ax = frac*lis[i][0] + (1 - frac)*lis[i+1][0]
        ay = frac*lis[i][1] + (1 - frac)*lis[i+1][1]
        print(str(ax)+" "+str(ay))
        quit()