// unchecked

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];
vector<int> rev_g[N];

vector<int> order;
bool used[N];

void topsort(int v) {
	used[v] = true;
	for (int u : g[v]) {
		if (!used[u]) {
			topsort(u);
		}
	}
	order.push_back(v);
}

int scc[N], color;

void dfs_scc(int v) {
	scc[v] = color;
	for (int u : rev_g[v]) {
		if (!scc[u]) {
			dfs_scc(u);
		}
	}
}

void build_scc() {
	// Complexity: O(N+M)
	order.clear();
	fill(used, used + N, false);
	for (int v = 0; v < N; ++v) {
		if (!used[v]) {
			topsort(v);
		}
	}
	reverse(order.begin(), order.end());
	fill(scc, scc + N, 0);
	color = 1;
	for (int v : order) {
		if (!scc[v]) {
			dfs_scc(v);
			++color;
		}
	}
	// vertex colors are already in topsort order
}