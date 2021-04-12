# my-library
This is a library with many things for competitive programming.

## Lib's rules

Formatting: Google

Comments: It is better not to comment code. Comment only if it is neccesary. For example, if you improve code later or if algorithm doesn't work in a well-known way. In the beginning specify used files ([example](/my-library/Data%20Structure/Persistent%20Array.cpp)). 

## Title

### Basic
Secondary algorithms.
* [Binary Search](/my-library/Basic/Binary%20search.cpp) - search algorithm that finds a target value (lower bound in O(log n) and sqrt(n) in O(log(x / EPS))).
* [Fast Allocator](/my-library/Basic/Fast%20Allocator.cpp) - fast memory allocator that incorrectly frees it.
* [Longest Increasing Subsequence](my-library/Basic/Longest%20Increasing%20Subsequence.cpp) - typically dynamic programming (DP) problem.
* [Fast input output](my-library/Basic/Fast%20input%20output.cpp) - simple input/output acceleration.
* [Pragmas](my-library/Basic/Pragmas.cpp) - useful pragmas.
* [Sorting algorithms](my-library/Basic/Sorting%20algorithms.cpp) - various sorts of the array.
* [Ternary search](my-library/Basic/Ternary%20search.cpp) - search algorithm that finds the maximum value for a convex upward array (all elements are unique) in O(log n).

### String
Algorithms with strings.
* [Hash string](/my-library/String/Hash%20string.cpp) - polynomial hash implementation.
* [LCP](/my-library/String/LCP.cpp) - longest common prefix array (LCP array) implementation; it stores the lengths of the longest common prefixes (LCPs) between all pairs of consecutive suffixes in a sorted suffix array.
* [Prefix function](/my-library/String/Prefix%20function.cpp) - for all prefixes, it stores the lengths of the longest prefix suffix that matches the beginning of the prefix and is not equal to it.
* [Suffix array](/my-library/String/Suffix%20array.cpp) - it stores a sorted suffix array.
* [Trie](/my-library/String/Trie.cpp) - it stores strings as a tree where the edges are letters and the vertices are prefixes.
* [Z function](/my-library/String/Z%20function.cpp) - for all suffixes except the string itself, it stores the lengths of the longest suffix prefix that matches the beginning of the prefix.

### Graph
Algorithms with graphs.
* [0-1 BFS](/my-library/Graph/0-1%20BFS.cpp) - BFS for a graph with edge weights 0 or 1.
* [0-k BFS](/my-library/Graph/0-k%20BFS.cpp) - BFS for a graph with integer edge weights from 0 to k.
* [BFS](/my-library/Graph/BFS.cpp) - breadth-first search.
* [Bellman-Ford with queue](/my-library/Graph/Bellman-Ford%20with%20queue.cpp) - Bellman-Ford implementation that is usually faster.
* [Bellman-Ford](/my-library/Graph/Bellman-Ford.cpp) - it builds array that stores the distances between fixed start and vertices, or `+-INF` if the distance does not exist.

### Data Structure
Tricky objects that allow you to do useful things.

### Math
Helpful math and combinatorial algorithms.

### Stresstest
Program to compare solutions.

## TODO

### Basic
* knuth's optimization
* divide and conquer
* stable_selection_sort, quick_sort, radix_sort

### String
(empty)

### Graph
* mincut
* mincost
* hopcroft–karp
* edmonds–karp
* 2-connected components
* boruvka's algorithm
* prim's algorithm

### Data Structure
* persistent seg tree lazy propagation
* suffix tree
* suffix automat
* palindromic tree
* Segment Tree Beats
* finish up treap
* seg tree for sum with alternating signs

### Math
* fft
* halfplane intersection
* minkowski sum
* burnside's theorem
* redfield–polya theorem
* improve geometry
