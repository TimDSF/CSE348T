# Credit: Yunfan Wang
s = int(input())
pts = set()
while len(pts) < 4:
    s = s + s//13 + 15
    pos = ( (s // 10)%10, s % 10)
    if pos not in pts:
        pts.add(pos)

move = 0
while len(pts) > 0:
    a = int(input())
    move += 1
    usrpos = ( (a // 10)%10, a % 10 )
    if usrpos in pts:
        print('You hit a wumpus!')
        pts.remove(usrpos)
    if len(pts) == 0:
        continue

    d = 1e12
    for p in pts:
        d = min(d, abs(p[0] - usrpos[0]) + abs(p[1] - usrpos[1]))
    print(d)

print('Your score is', move, 'moves.')
