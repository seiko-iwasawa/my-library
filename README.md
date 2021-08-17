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
* [Fast input output](my-library/Basic/Fast%20input%20output.cpp) - simple input/output acceleration.
* [Pragmas](my-library/Basic/Pragmas.cpp) - useful pragmas.
* [Sorting algorithms](my-library/Basic/Sorting%20algorithms.cpp) - various sorts of the array.
* [Ternary search](my-library/Basic/Ternary%20search.cpp) - search algorithm that finds the maximum value for a convex upward array (all elements are unique) in O(log n).

### DP
All about dynamic programming.
* [1D1D O(n)](/my-library/Basic/1D1D%20O(n).cpp) - dp optimization for special tasks.
* [1D1D](/my-library/Basic/1D1D.cpp) - dp optimization for special tasks.
* [Longest Increasing Subsequence](my-library/Basic/Longest%20Increasing%20Subsequence.cpp) - typically dynamic programming (DP) problem.

### String
Algorithms with strings.
* [Aho-Corasik](/my-library/String/Aho-Corasik.cpp) - it builds suffix links in trie.
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
* [Bellman-Ford](/my-library/Graph/Bellman-Ford.cpp) - it builds an array that stores the distances between fixed start and vertices, or `+-INF` if the distance does not exist.
* [Centroid Decomposition](/my-library/Graph/Centroid%20Decomposition.cpp) - it builds a centroid tree, where the size of each subtree is no more than half the size of the parent.
* [Cut edges](/my-library/Graph/Cut%20edges.cpp) - it builds an array of cut edges for a graph that does not have multiple edges and loop. Cut edge is an only edge that connects two or more components.
* [Cut vertices](/my-library/Graph/Cut%20vertices.cpp) - it builds an array of of cut vertices for a graph. Cut vertex if an only vertex that connects two or more components.
* [DFS tree](/my-library/Graph/DFS%20tree.cpp) - DFS for a tree.
* [DFS](/my-library/Graph/DFS.cpp) - depth-first search.
* [Dijkstra O(Elog)](/my-library/Graph/Dijkstra%20O(Elog).cpp) - Dijkstra implementation with priority queue.
* [Dijkstra O(VE)](/my-library/Graph/Dijkstra%20O(VE).cpp) - for graph with non-negative edge weights, it builds an array that stores the distances between fixed start and vertices, or `INF` if the distance does not exist.
* [Dinic](/my-library/Graph/Dinic.cpp) - it solves max-flow problem.
* [ETT](/my-library/Graph/ETT.cpp) - it builds euler tour technique.
* [Eulerian cycle](/my-library/Graph/Eulerian%20cycle.cpp) - it finds a cycle in an undirected graph which traverse all edges exactly once.
* [Eulerian path](/my-library/Graph/Eulerian%20path.cpp) - it finds a path in undirected graph which traverse traverse all edges exactly once.
* [Floyd-Warshall](/my-library/Graph/Floyd-Warshall.cpp) - it finds the distances between all pairs of vetices, or `+-INF` if the distance does not exist.
* [Ford-Fulkerson](/my-library/Graph/Ford-Fulkerson.cpp) - is solves max-flow problem.
* [HLD](/my-library/Graph/HLD.cpp) - it builds heavy-light decomposition of the tree. It divides the edges into groups so that between the root and each vertex there are at most `log` groups.
* [Kuhn](/my-library/Graph/Kuhn.cpp) - it solves maximum bipartite matching problem.
* [LCA binary jumps](/my-library/Graph/LCA%20binary%20jumps.cpp) - for each vertex in the tree, it builds an array of binary jumps (`2**k`-th parent for each k). Then, it answers to a query "least common ancestor for v and u" (LCA) in O(log n).
* [LCA sparse table](/my-library/Graph/LCA%20sparse%20table.cpp) - it builds ETT pairs of numbers (`depth`, `vertex`). Then, it builds sparse table for this array and answers to a query "least common ancestor for v and u" (LCA) in O(1).
* [MST](/my-library/Graph/MST.cpp) - it builds a minimal spanning tree for the graph using Kruskal's algorithm.
* [Retrograde analysis](/my-library/Graph/Retrograde%20analysis.cpp) - it calculates all states (`WIN`, `DRAW` or `LOSE`) for a symmetric game on directred graph.
* [SCC](/my-library/Graph/SCC.cpp) - it builds strongly connected components.
* [Topsort](/my-library/Graph/Topsort.cpp) - it sorts DAG's vertexes such that all edges go forward.
* [Vengeric algorithm](/my-library/Graph/Vengeric%20algorithm.cpp) - it solves maximum bipartite matching problem for a weighted graph.

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
* deterministic finite automation

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
* halfplane intersection
* minkowski sum
* burnside's theorem
* redfield–polya theorem
* improve geometry
