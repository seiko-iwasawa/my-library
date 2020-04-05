// unchecked

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int N = 1e5;

struct Edge { int v, u, w; };
vector<Edge> g[N];
int dist[N];

void bfs_01(int start) {
	// Complexity: O(M)
	fill(dist, dist + N, N);
	deque<int> d({start});
	dist[start] = 0;
	while (!d.empty()) {
		int v = d.front();
		d.pop_front();
		for (Edge e : g[v]) {
			if (dist[e.u] > dist[e.v] + e.w) {
				if (dist[e.u] == dist[e.v]) {
					d.push_front(e.u);
				}
				else {
					d.push_back(e.u);
				}
				dist[e.u] = dist[e.v] + e.w;
			}
		}
	}
}