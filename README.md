# my-library
This is a library with many things for competitive programming.

## Lib's rules
This library just shows possible implementations, it may not be very good or convenient.

Comments: It is better not to comment code. Comment only if it is neccesary. For example, if you improve code later or if algorithm doesn't work in a well-known way. In the beginning specify used files ([example](/my-library/Data%20Structure/Persistent%20Array.cpp)).

Filenames: File names must start with a capital letter (or a digit), exluding files in the folder `Stresstest`. You can use spaces.

## Title

### Basic
* [Binary Search](/my-library/Basic/Binary%20search.cpp) - [link1](https://codeforces.com/edu/course/2/lesson/6/1) [link2](https://en.wikipedia.org/wiki/Binary_search_algorithm) - search algorithm that finds a target value (lower bound in O(log n) and sqrt(n) in O(log(x / EPS))).
* [Fast Allocator](/my-library/Basic/Fast%20Allocator.cpp) - [link1](https://os.phil-opp.com/allocator-designs/#bump-allocator) - fast memory allocator that incorrectly frees it.
* [Fast input output](my-library/Basic/Fast%20input%20output.cpp) - simple input/output acceleration.
* [Pragmas](my-library/Basic/Pragmas.cpp) - useful pragmas.
* [Sorting algorithms](my-library/Basic/Sorting%20algorithms.cpp) - [link1](https://en.wikipedia.org/wiki/Sorting_algorithm) - various sorts of the array.
* [Ternary search](my-library/Basic/Ternary%20search.cpp) - [link1](https://cp-algorithms.com/num_methods/ternary_search.html) [link2](https://en.wikipedia.org/wiki/Ternary_search) - search algorithm that finds the maximum value for a convex upward array (all elements are unique) in O(log n).
* [Tricks](my-library/Basic/Tricks.cpp) - [link1](https://codeforces.com/blog/entry/15643
) [link2](https://codeforces.com/blog/entry/74684
) [link3](https://codeforces.com/blog/entry/91347
) - many useful things in C++ for competitive programming.

### DP
* [1D1D O(n)](/my-library/DP/1D1D%20O(n).cpp) - [link1](https://codeforces.com/blog/entry/8219?#comment-139241) - dp optimization for special tasks.
* [1D1D](/my-library/DP/1D1D.cpp) - [link1](https://www.sites.google.com/site/ubcprogrammingteam/news/1d1ddynamicprogrammingoptimization-parti) - dp optimization for special tasks.
* [Knuth](/my-library/DP/Knuth.cpp) - dp optimization for special 2D tasks.
* [Longest Increasing Subsequence](my-library/DP/Longest%20Increasing%20Subsequence.cpp) `aka LIS` - typically DP-problem.

### String
* [Aho-Corasik](/my-library/String/Aho-Corasik.cpp) - it builds suffix links in trie.
* [Hash string](/my-library/String/Hash%20string.cpp) - polynomial hash implementation.
* [LCP](/my-library/String/LCP.cpp) - longest common prefix array (LCP array) implementation; it stores the lengths of the longest common prefixes (LCPs) between all pairs of consecutive suffixes in a sorted suffix array.
* [Prefix function](/my-library/String/Prefix%20function.cpp) - for all prefixes, it stores the lengths of the longest prefix suffix that matches the beginning of the prefix and is not equal to it.
* [Suffix array](/my-library/String/Suffix%20array.cpp) - it stores a sorted suffix array.
* [Trie](/my-library/String/Trie.cpp) - it stores strings as a tree where the edges are letters and the vertices are prefixes.
* [Z function](/my-library/String/Z%20function.cpp) - for all suffixes except the string itself, it stores the lengths of the longest suffix prefix that matches the beginning of the prefix.

### Graph
* [0-1 BFS](/my-library/Graph/0-1%20BFS.cpp) - BFS for a graph with edge weights 0 or 1.
* [0-k BFS](/my-library/Graph/0-k%20BFS.cpp) - BFS for a graph with integer edge weights from 0 to k.
* [BFS](/my-library/Graph/BFS.cpp) - breadth-first search.
* [Bellman-Ford](/my-library/Graph/Bellman-Ford.cpp) - it builds an array that stores the distances between fixed start and vertices, or `+-INF` if the distance does not exist.
* [Centroid Decomposition](/my-library/Graph/Centroid%20Decomposition.cpp) - it builds a centroid tree, where the size of each subtree is no more than half the size of the parent.
* [Cut edges](/my-library/Graph/Cut%20edges.cpp) - it builds an array of cut edges for a graph that does not have multiple edges and loop. Cut edge is an only edge that connects two or more components.
* [Cut vertices](/my-library/Graph/Cut%20vertices.cpp) - it builds an array of cut vertices for a graph. Cut vertex if an only vertex that connects two or more components.
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
* [MST](/my-library/Graph/MST.cpp) - [link1](https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html) - it builds a minimal spanning tree for the graph using Kruskal's algorithm.
* [Retrograde analysis](/my-library/Graph/Retrograde%20analysis.cpp) - it calculates all states (`WIN`, `DRAW` or `LOSE`) for a symmetric game on directred graph.
* [SCC](/my-library/Graph/SCC.cpp) - it builds strongly connected components.
* [SPFA](/my-library/Graph/SPFA.cpp) - [link1](https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm) [] - Bellman-Ford implementation that is usually faster.
* [Topsort](/my-library/Graph/Topsort.cpp) - it sorts DAG's vertexes such that all edges go forward.
* [Vengeric algorithm](/my-library/Graph/Vengeric%20algorithm.cpp) - it solves maximum bipartite matching problem for a weighted graph.

### Data Structure
For any structure, we can update it and get information from. Some structures have a special build stage.
* [Convex Hull Trick](/my-library/Data%20Structure/Convex%20Hull%20Trick.cpp) `aka CHT` - `update`: add lines kx+b in non-increasing order of k in O(1) armotized; `get`: get min kx+b for chosen x in O(logn).
* [Deque](/my-library/Data%20Structure/Deque.cpp) - `update`: push/erase first/last element in O(1); `get`: get the first/last element in O(1).
* [Disjoint Set Union](/my-library/Data%20Structure/.cpp) `aka DSU` - `build`: O(n); `update`: join two sets in O(A^-1(n)) armotized; `get`: find the leader of the set in O(A^-1(n)) armotized. 
* [Fenwick](/my-library/Data%20Structure/Fenwick.cpp) - `update`: update the element in O(logn); `get`: get function on the segment in O(logn).
* [Heap](/my-library/Data%20Structure/.cpp) - `build`: O(n); `update`: insert element in O(logn), erase max element in O(logn); `get`: get the max element.
* [Li Chao](/my-library/Data%20Structure/Li%20Chao.cpp) - `update`: add line kx+b in O(logC); `get`: get min kx+b for chosen x in O(logn).
* [Persistent Array](/my-library/Data%20Structure/Persistent%20Array.cpp) - `update`: set a_i=x in O(logn); `get`: get a_i in O(logn).
* [Persistent Segment Tree](/my-library/Data%20Structure/Persistent%20Segment%20Tree.cpp) - `update`: update the element in O(logn); `get`: get function on the segment in O(logn).
* [Persistent Stack](/my-library/Data%20Structure/Persistent%20Stack.cpp) - `update`: push back in O(1); `get`: get back in O(1).
* [Queue](/my-library/Data%20Structure/Queue.cpp) - `update`: push element at the end in O(1), pop element from the top in O(1); `get`: get the first element in O(1).
* [Segment Tree lazy propagation](/my-library/Data%20Structure/Segment%20Tree%20lazy%20propagation.cpp) - `update`: change values on the segment in O(logn); `get`: get function on the segment in O(logn).
* [Segment Tree](/my-library/Data%20Structure/Segment%20Tree.cpp) - `update`: update the element in O(logn); `get`: get function on the segment in O(logn).
* [Skiplist with implicit keys](/my-library/Data%20Structure/Skiplist%20with%20implicit%20keys.cpp) - doubly linked list that can do many things in O(logn).
* [Skiplist](/my-library/Data%20Structure/Skiplist.cpp) - it can do all whatever BST can.
* [Sparse Table](/my-library/Data%20Structure/Sparse%20Table.cpp) - [link1](https://cp-algorithms.com/data_structures/sparse-table.html) - `build`: O(nlogn); `get`: get function on the segment in O(1).
* [Split Rebuild](/my-library/Data%20Structure/Split%20Rebuild.cpp) - powerful modification for sqrt decomposition with armotized time complexity.
* [Stack](/my-library/Data%20Structure/Stack.cpp) - `update`: push back in O(1); `get`: get back in O(1).
* [Top Bottom Segment Tree](/my-library/Data%20Structure/Top%20Bottom%20Segment%20Tree.cpp) - fast implementation of segment tree.
* [Treap with implicit keys](/my-library/Data%20Structure/Treap%20with%20implicit%20keys.cpp) - doubly linked list that can do many things in O(logn).
* [Treap](/my-library/Data%20Structure/Treap.cpp) - possible BST (Binary Search Tree) implementation.

### Math
* [Berlekamp-Massey mod2](/my-library/Math/Berlekamp-Massey%20mod2.cpp) - Berlekamp-Massey in the field modulo 2.
* [Berlekamp-Massey](/my-library/Math/Berlekamp-Massey.cpp) - it finds the shortest linear feedback shift register in O(nk). 
* [Big Integer](/my-library/Math/Big%20Integer.cpp) - template for working with long arithmetic.
* [Chinese Remainder Theorem](/my-library/Math/Chinese%20Remainder%20Theorem.cpp) - [link1](https://en.wikipedia.org/wiki/Chinese_remainder_theorem#Case_of_two_moduli) + [link2](https://en.wikipedia.org/wiki/Chinese_remainder_theorem#Generalization_to_non-coprime_moduli) - it finds the smallest solution for a system of equation in two modules.
* [FFT](/my-library/Math/FFT.cpp) - [link1](https://codeforces.com/blog/entry/43499) [link2](https://cp-algorithms.com/algebra/fft.html) - implementation of discrete fourier transformation in O(nlogn).
* [GCD extended](/my-library/Math/GCD%20extended.cpp) - [link1](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html) - it finds a solution to the equation ax+by=gcd(a, b).
* [GCD](/my-library/Math/GCD.cpp) - [link1](https://cp-algorithms.com/algebra/euclid-algorithm.html) - it finds the greatest common divisor.
* [Gauss mod2](/my-library/Math/Gauss%20mod2.cpp) - Gauss in the field modulo 2.
* [Gauss](/my-library/Math/Gauss.py) - it finds a solution for a system of linear equations.
* [Geometry](/my-library/Math/Geometry.cpp) - geometry template.
* [Karatsuba intmul](/my-library/Math/Karatsuba%20intmul.cpp) - possible implementation of the multiplication two integers using the Karatsuba algorithm.
* [Karatsuba](/my-library/Math/Karatsuba.cpp) - it multiplies two polynomials in O(n^log2(3)).
* [Kth permutation](/my-library/Math/Kth%20permutation.cpp) - it builds the kth permutation in lexicographic order.
* [Matrix](/my-library/Math/Matrix.cpp) - template for working with matrices.
* [Miller-Rabin](/my-library/Math/Miller-Rabin.cpp) - [link1](https://cp-algorithms.com/algebra/primality_tests.html#toc-tgt-2) [link2](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test) - probabilistic primality test.
* [Modular arithmetic](/my-library/Math/Modular%20arithmetic.cpp) - template for working with a field modulo.
* [Next permutation](/my-library/Math/Next%20permutation.cpp) - it builds the next permutation in lexicographic order.
* [Pollard](/my-library/Math/Pollard.cpp) - [link1](https://cp-algorithms.com/algebra/factorization.html#toc-tgt-5) [link2](https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm) - an algorithm for factorization.
* [Pollard (py)](/my-library/Math/Pollard.py) - Python implementation of Pollard's rho algorithm.
* [Sieve of Eratosthenes](/my-library/Math/Sieve%20of%20Eratosthenes.cpp) - [link1](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html) - it builds the smallest prime divisor for each number in O(nloglogn).

### Stresstest
Programs to compare solutions.

## TODO

### DP
* divide and conquer
* lambda
* dp by submasks
* sos-dp

### String
* deterministic finite automation
* tandem repeats
* manacher's algorithm

### Graph
* mincut
* mincost
* hopcroft–karp
* edmonds–karp
* 2-connected components
* boruvka's algorithm
* prim's algorithm
* stoer-wagner algorithm
* sum of games
* 2-SAT

### Data Structure
* non-amortized dsu
* persistent seg tree lazy propagation
* suffix tree
* suffix automat
* palindromic tree
* Segment Tree Beats
* finish up treap
* seg tree for sum with alternating signs
* disjoint sparse table
* minimum stack
* minimum queue
* sqrt decomposition
* binary trie

### Math
* ntt
* halfplane intersection
* minkowski sum
* burnside's theorem
* redfield–polya theorem
* improve geometry
* mobius function
* euler's totient function