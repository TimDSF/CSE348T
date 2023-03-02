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
Let $O$ be the origin, $X$ be $(x, 0)$. A point $B$ if contained in the triangle formed by $A$ if and only if the angle $\overleftarrow{OA}$ is larger than $\overleftarrow{OB}$ and the angle $\overleftarrow{XA}$ is smaller than $\overleftarrow{XB}$ (angles are calculated with the positive $x$-direction). So, if we sort all the elements by the angle with $X$ in ascending order, then, each inversion on the angle with $O$ tells a containment. The ___CSE 347___ way of counting inversions is using ___Divide and Conquer___, which is error-prone. So, we will use Fenwick Tree (or Segment Tree). Noticed that we are counting the values of the containment, so, instead of finding the number of inversion, we need to accumulate the value smaller value in the inversion to the solution for the larger value.

## C - 