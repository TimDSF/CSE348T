# NAQ20

## Introduction
Here is the link for the contest: https://mcpc20.kattis.com/. 

## Sample Solutions
Here are the sample solutions to A, B, D, E.

### A - Kitchen Measurements
Graph search with heuristic.

### B- Exploding CPU
Make a table beforehand. Use the commented program to discover all possible Zeisel Numbers.

### C - Ticket to Ride
To be continued ..:(

### D - Razbibriga
Brutal force the four corners of the square, then use some combinatorics. (Credit: Yiheng Yao)

### E - Mega Inversions
For each number as the middle one, find out how many are larger in the front and how many are smaller in the back, then multiply these two number together and sum over all possible middles. Binary Index Tree (Fenwick Tree) is the way to efficiently get how many numbers are larger / smaller. Reference to BIT: https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/ or https://oi-wiki.org/ds/fenwick/.
