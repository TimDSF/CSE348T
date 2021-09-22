import math

def run():
  t = int(input())
  trees = []
  for i in range(t):
    x,y,r = list(map(int,input().split()))
    trees.append((x,y,r))
  R,d = list(map(int,input().split()))
  d2 = d*d

  # Split into 3 cases
  # - Out of range
  # - Just within range
  # - Tree entirely within range
  def arcBounds(tree):
    x,y,r = tree
    rR = r + R
    D2 = x*x + y*y
    D = math.sqrt(D2)
    # Out of range
    if d+rR <= D: # never reach tree
      return []
    A = math.atan2(y, x) # mid of arc
    # Tree entirely within range
    if D2 <= rR*rR + d2:
      th = math.asin(rR/D)
    # Tree just within
    else:
      # Use cosine rule: c^2 = a^2 + b^2 - 2ab*cos(th)
      th = math.acos((D2 + d2 - rR*rR)/(2*d*D))
    # Need to split up into sections if we cross the boundary (> math.pi or < -math.pi)
    if (A-th < -math.pi):
      return [(A-th+math.tau,math.pi), (-math.pi,A+th)]
    if (A+th > math.pi):
      return [(-math.pi,A+th-math.tau),(A-th,math.pi)]
    return [(A-th, A+th)]

  # Stores at what range of degrees the boar
  # charge into a tree
  arcs = list(map(arcBounds, trees))
  # Flatten our list
  flatten = lambda l: [item for sublist in l for item in sublist]
  arcs = flatten(arcs)
  arcs = sorted(arcs)

  # Scan to find opening
  if (len(arcs) == 0):
    print(1)
    return

  # print(arcs)
  lo = arcs[0][0]
  hi = arcs[0][1]
  conut = 0
  offset = 0

  for al, ah in arcs[1:]:
    conut += 1
    # Special terminal case
    if (conut == len(arcs)-1):
      if (ah - math.tau >= lo):
        offset = None
      else:
        offset = lo
    # Test if we are starting within last arc
    if al <= hi:
      hi = max(hi,ah)
    # Otherwise, we found a break in between arcs
    else:
      offset = al
      break

  # print(offset)

  # Special case where entire circle is covered by arcs
  if (offset is None):
    print(0)
    return

  # Offset all arcs to be within [0, math.tau]
  arcs = sorted(list(map(lambda arc: (arc[0]-offset + math.tau, arc[1]-offset + math.tau) if (arc[0]-offset < 0 and arc[1]-offset < 0) else (arc[0]-offset, arc[1]-offset), arcs)))

  # if (arcs[0][0] != 0.0):
  #   print("ERROR: offset")
  #   return

  # print(arcs)

  # Scan through to find covered arcs
  lo = arcs[0][0]
  hi = arcs[0][1]
  tot = 0
  for al, ah in arcs[1:]:
    if (al > hi):
      tot += hi-lo
      lo = al
      hi = ah
    else:
      hi = max(hi,ah)
  # print(tot, (lo,hi), hi-lo)
  tot += hi-lo

  print(1-(tot/math.tau))

run()