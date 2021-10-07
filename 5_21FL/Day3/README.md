# LeetCode / ICPC Session: Day 3 (***Saturday Oct/9***)

## Topics
_once upon a time - Fibonacci_  
Fibonacci sequence is famous for multiple reasons. In case you are unfamiliar with it, it is a sequence that starts with `1` and `1`; then, iteratively, we have each number being the sum of the previous two. Specifically, we have

```math
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
```

How many ways can you calculate the n<sup>th</sup> number of the Fibonacci sequence?

Here, we have 8 methods to do so, with time complexity ranging of `O(2^n)` to `O(log n)`.

https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/  

For a reference, here are the methods:

| index | description | time complexity | space complexity |
| ----- | ----------- | --------------- | ---------------- |
| 1 | naive recursion | `O(2^n)` | `O(n)` |
| 2 | memorized recursion | `O(n)` | `O(n)` |
| 3 | dynamic programming | `O(n)` | `O(n)` |
| 4 | iterative method | `O(n)` | `O(1)` |
| 5 | matrix product | `O(n)` | `O(n)` |
| 6 | matrix exponentiation | `O(log n)` | `O(n)` |
| 7 | recursion formula | `O(log n)` | `O(n)` |
| 8 | close-form expression | `O(log n)` | `O(1)` |

But, my all-time favorite is the non-recursive solution to the matrix exponentiation, which has:

| index | description | time complexity | space complexity |
| ----- | ----------- | --------------- | ---------------- |
| 6+ | matrix exponentiation | `O(log n)` | `O(1)` |
