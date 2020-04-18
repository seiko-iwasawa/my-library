// unchecked

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3;
const int M = 2e4;

struct Edge {
	int v, u, c, f;

	int r() { return c - f; }
} edges[M];
vector<int> g[N];
int s, t;

void add_oriented_edge(int v, int u, int c) {
	static int i = 0;
	edges[i] = { v, u, c, 0 };
	edges[i + 1] = { u, v, 0, 0 };
	g[v].push_back(i++);
	g[u].push_back(i++);
}

int f;
bool used[N];

bool dfs(int v) {
	if (v == t) {
		return true;
	}
	used[v] = true;
	for (int i : g[v]) {
		if (edges[i].r() && !used[edges[i].u] && dfs(edges[i].u)) {
			++edges[i].f;
			--edges[i ^ 1].f;
			return true;
		}
	}
	return false;
}

void ford_fulkerson() {
	f = 0;
	do {
		fill(used, used + N, false);
	} while (dfs(s));
}