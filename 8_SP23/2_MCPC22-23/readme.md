# MCPC22

## Introduction
Here is the link for the contest: https://mcpc22.kattis.com/. 

## Official Solutions
We have not found the official solution to this competition.  

## A - Blueberry Waffle
### Category
Simulation
### Difficulty
Easy ($1.3$)
### Solution: $O(1)$
Simply check the number of rotations it does, and judge based on the decimal values (___down___ if 0.25 to 0.75, ___up___ otherwise).

## B - Triangle Containment
### Category
Computational Geometry, Counting Inversion, Merge Sort, Fenwick Tree.
### Difficulty
Hard ($7.5$)
### Solution: $O(n\log n)$
Let $O$ be the origin, $X$ be $(x, 0)$. A point $B$ if contained in the triangle formed by $A$ if and only if the angle $\overrightarrow{OA}$ is larger than $\overrightarrow{OB}$ and the angle $\overrightarrow{XA}$ is smaller than $\overrightarrow{XB}$ (angles are calculated with the positive $x$-direction). So, if we sort all the elements by the angle with $X$ in ascending order, then, each inversion on the angle with $O$ tells a containment. The ___CSE 347___ way of counting inversions is using ___Divide and Conquer___, which is error-prone. So, we will use Fenwick Tree (or Segment Tree). Noticed that we are counting the values of the containment, so, instead of finding the number of inversion, we need to accumulate the value smaller value in the inversion to the solution for the larger value.

## C - Everything Is A Nail
### Category
Dynamic Programming, Bitmask DP, Dimension Reduction DP
### Difficulty
Median ($5.2$)
### Solution: $O(64n)$
This is a DP problem, where the state denotes the current status of the tools. Let $dp[i][\overline{c_1c_2c_3a_1a_2a_3}]$ be the states, where $i$ is the current tool we are considering, and $\overline{c_1c_2c_3a_1a_2a_3}$ is the status. $\overline{c_1c_2c_3a_1a_2a_3}$ are the binary representation of the current availability of the tools, where $\overline{c_1c_2c_3}$ indicates which tool is currently using, and $\overline{a_1a_2a_3}$ indicates which tool is still yet to be used. So, for each task, you can choose to finish it or not. If you choose to finish it, then, you could come from two states: where the tool required is currently in use and where it is not currently used. And for simplicity, we will also update two states in the $DP$ array: where I keep the used tool available, and where I dropped the current tool.

## D - Champernowne Count
### Category
Modulo Arithmetic
### Difficulty
Easy ($3.4$)
### Solution: $O(n)$
Appending the next number to the cumulative number, while taking modulo along the way.

## E - Color Tubes
### Category
Simulation
### Difficulty
Median ($6.6$)
### Solution: $O(20n)$
Tower of Hanoi with $n+1$ pillars but $3$ maximum height. So, keep the color in the base for each pillar, and find the other two balls with the same color, switch with the two on top of that pillar. Lots of details.

## F - Food Processor
### Category
Simulation
### Difficulty
Median ($6.4$)
### Solution: $O(n\log n)$
Sort the knifes by size descending order. Keep using the current best knife with shortest time, until we have unlocked the next knife. The time is calculated as a exponential decay, using logarithm.

## G - Digits of Unity
### Category
Inclusion–exclusion principle (Poincaré's Theorem)
### Difficulty
Hard ($7.9$)
### Solution
IDK yet.

## H - Hunt the Wumpus
### Category
Simulation
### Difficulty
Easy ($2.6$)
### Solution: $O(n)$
Simulate the game. Output correspondingly.

## I - Branch Manager
### Category
Depth-First Search, Independent Pointer Technique
### Difficulty
Median ($6.6$)
### Solution: $O(n)$
Build the tree, and then, traverse on tree using Depth-First Search. During the traversal, keep trace of elements on the chain from the root to the current node, as well as all the nodes that has been dropped. Have an independent pointer that exams the destinations in the provided order. If the node is in the dropped set, then, it cannot be reached and we should terminate; if it is on the current chain, then, it can be reached, and we keep examining the next element; if it is not yet visited, then, proceed the DFS. The time is $O(n)$ because the DFS and the independent pointer each goes through their respective $O(n)$ elements once.

## J - Advertising ICPC
### Category
Bitmask, Inclusion–exclusion principle (Poincaré's Theorem)
### Difficulty
Hard ($8.3$)
### Solution 1 (DFS): $O(2^n)$
Using DFS, we can examine the location where $2\times2$ ICPC block can be placed. While doing the DFS, we also keep track of the number of ICPC blocks we have placed. After finish the DFS, if the number of flags is odd, the solution should be added to the accumulator, and if the number of flags is even, it should be taken off. This is because of double counting while we place all possible characters on the non-occupied positions. So, we need to use the Poincaré's Theorem to count the union.
### Solution 2 (BFS): $O(n^2)$
To be finished.

## K - Bog of Eternal Stench
### Category
Shortest Path
### Difficulty
Hard ($8.2$)
### Solution
IDK yet.

## L - I Could Have Won
### Category
Simulation
### Difficulty
Easy ($3.1$)
### Solution: $O(kn)$
Try every possible $k$, simulate the game.

## M - Creative Accounting
### Category
Prefix Sum
### Difficulty
Median ($6.3$)
### Solution: $O(k^2 + n)$
Calculate the prefix sum. Calculate the number of positive elements for each possible interval length with each possible starting location. Maintain the maximum and minimum. The provided solution have unnecessary calculations and is $O(kn)$.
