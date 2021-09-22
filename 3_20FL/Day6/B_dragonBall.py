from heapq import heappush, heappop
from collections import defaultdict
from itertools import permutations
import math
import time
import sys

# dijkstra from start to end
def dijkstra(graph, s, e):
  pq = []
  v = [math.inf for i in range(len(graph))]
  heappush(pq, (0,s))
  # print(f"from {s} to {e}", file=sys.stderr)
  while (len(pq) > 0):
    curCost, curNode = heappop(pq)
    # print(f"v {v[curNode]}: {curNode} | {curCost}", file=sys.stderr)
    if (v[curNode] < curCost):
      continue
    v[curNode] = curCost
    # Check if we are at terminal state
    if (curNode == e):
      return curCost
    # Propagate
    for adj, cost in graph[curNode]:
      nextCost = curCost + cost
      # print(f"next {adj}: {nextCost} | {v[adj]}", file=sys.stderr)
      if (nextCost < v[adj]):
        heappush(pq, (nextCost,adj))
        v[adj] = nextCost
  return math.inf

def run():
  init_t = time.time()
  # Graph construction
  n,m = [int(i) for i in input().split()] # Init params
  graph = [[] for i in range(n)] # Store links in adjList
  for i in range(m):
    a,b,t = [int(i) for i in input().split()] # Read links
    graph[a-1].append((b-1,t))
    graph[b-1].append((a-1,t))

  # Read in DragonBall locations
  dballs = list(set([int(i)-1 for i in input().split()]))
  # print(f"used: {(time.time() - init_t)*1000:.3f}")
  sys.stdout.flush()

  # We iterate through all possible permutations of ball visiting order
  v_order = list(permutations(dballs))

  # First compute and memoize |dballs|^2 routes between the locations
  routes = defaultdict(lambda:defaultdict(int))

  for i in range(len(dballs)):
    for j in range(i+1,len(dballs)):
      s = dballs[i]
      e = dballs[j]
      # dijkstra through the graph for min distance and memoize
      dist = dijkstra(graph, s, e)
      # print((s,e,dist), file=sys.stderr)
      routes[s][e] = dist
      routes[e][s] = dist
  # Store also from 0 to all dball locations
  for l in dballs:
    dist = dijkstra(graph, 0, l)
    routes[0][l] = dist
    routes[l][0] = dist

  # Use all possible permutations to check min
  minCost = math.inf
  for order in v_order:
    cost = routes[0][order[0]]
    for i in range(1,len(order)):
      cost += routes[order[i-1]][order[i]]
    minCost = min(minCost, cost)

  if (minCost == math.inf):
    print(-1)
    return
  else:
    print(minCost)
    return

run()