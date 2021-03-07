import math

def run():
  w,h = [int(i) for i in input().split()]
  blocks = math.gcd(w,h)
  if blocks == 1:
    print(1 if h%2 == 1 and w%2 == 1 else 0)
  else:
    nw = w//blocks
    nh = h//blocks
    print(blocks*(1 if nh%2 == 1 and nw%2 == 1 else 0))

run()