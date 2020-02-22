C, L = [int(i) for i in input().split()]
cows = []
lots = []
for c in range(C):
	min_c, max_c = [int(i) for i in input().split()]
	cows.append((min_c, max_c))
for l in range(L):
	min_l, max_l = [int(i) for i in input().split()]
	lots.append((min_l, max_l))

cows = sorted(cows, key=lambda x: (x[1], x[0]), reverse=True)
lots = sorted(lots, key=lambda x: ())