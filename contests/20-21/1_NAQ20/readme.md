# NAQ20

## Introduction
Here is the link for the contest: https://naq20.kattis.com/. 

## Sample Solutions
Here are the sample solutions to A, C, D, F, H. And for the official explanations to B, E, G, H, you can find them at https://145cef76-c5df-4a48-bb1b-b53188be3f31.filesusr.com/ugd/ae0b32_e8fcdb846eed42cc8b1f234bb4e59c83.pdf.

### A - Cantina of Babel
My solution contains finding the Strong Connected Component (SCC) of the graph of communication. Given each language being a node, with each person affiliated with the node they speak. For each person who speaks language _L_ and understands language _J1, ..., Jn_, we can add an edge from _L_ to each of the _Jk_'s. Then finding the SCC containing the most people _m_, the final answer would be _N_ - _m_.  
The algorithm to find the SCC I used is Tarjan, with a sample code attached as well. More detailed explanation about Tarjan can be found at https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/, or about SCC at here https://oi-wiki.org/graph/scc/.
### C - Eight Queens
Checking if there are ___8 queens___ on the board, and if there is any queen that can reach others.
### D - Flexible Spaces
Brutal force each pair of partitioning lines.
### F - Simon Says
Do exactly as what _Simon_ says.
### H
A Dynamic Programming (DP) problem. More detail at the official solution document. Or refer to the sample code if necessary.