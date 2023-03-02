# MCPC22

## Introduction
Here is the link for the contest: https://mcpc22.kattis.com/. 

## Official Solutions
We have not found the official solution to this competition.  

## A - Blueberry Waffle
### Category
Check-in
### Difficulty
Easy
### Solution
Simply check the number of rotations it does, and judge based on the decimal values (___down___ if 0.25 to 0.75, ___up___ otherwise).

## B - Triangle Containment
### Category
Computational Geometry, Counting Inversion, Merge Sort, Fenwick Tree.
### Difficulty
Hard
### Solution
Let $O$ be the origin, $X$ be $(x, 0)$. A point $B$ if contained in the triangle formed by $A$ if and only if the angle $\overrightarrow{OA}$ is larger than $\overrightarrow{OB}$ and the angle $\overrightarrow{XA}$ is smaller than $\overrightarrow{XB}$ (angles are calculated with the positive $x$-direction). So, if we sort all the elements by the angle with $X$ in ascending order, then, each inversion on the angle with $O$ tells a containment. The ___CSE 347___ way of counting inversions is using ___Divide and Conquer___, which is error-prone. So, we will use Fenwick Tree (or Segment Tree). Noticed that we are counting the values of the containment, so, instead of finding the number of inversion, we need to accumulate the value smaller value in the inversion to the solution for the larger value.

## C - Everything Is A Nail
### Category
DP, Bitmask, Dimension Reduction
### Difficulty
Median
### Solution
This is a DP problem, where the state denotes the current status of the tools. Let $dp[i][c_1c_2c_3a_1a_2a_3]$ be the states, where $i$ is the current tool we are considering, and $c_1c_2c_3a_1a_2a_3$ is the status. $c_1c_2c_3a_1a_2a_3$ are the binary representation of the current availability of the tools, where $c_1c_2c_3$ indicates which tool is currently using, and $a_1a_2a_3$ indicates which tool is still yet to be used. So, for each task, you can choose to finish it or not. If you choose to finish it, then, you could come from two states: where the tool required is currently in use and where it is not currently used. And for simplicity, we will also update two states in the $DP$ array: where I keep the used tool available, and where I dropped the current tool.

## X - XXX
### Category
### Difficulty
### Solution

## X - XXX
### Category
### Difficulty
### Solution

## X - XXX
### Category
### Difficulty
### Solution

## X - XXX
### Category
### Difficulty
### Solution

## X - XXX
### Category
### Difficulty
### Solution