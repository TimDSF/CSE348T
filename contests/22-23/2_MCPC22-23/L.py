# Credit: Yunfan Wang
s = input()
n = len(s)
ans = []

for k in range(1, n+1):
    atot = btot = 0
    a = b = 0
    for c in s:
        if c == 'A':
            a+=1
        else:
            b+=1
        if a>=k:
            atot += 1
            a = b = 0
        elif b>=k:
            btot += 1
            a = b = 0
    if atot > btot:
        ans += [k]

print(len(ans))
if len(ans) != 0:
    print(' '.join(map(str, ans)))

# ABABAABABBABBAB
