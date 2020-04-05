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

int css[N], color;

void dfs_css(int v) {
	css[v] = color;
	for (int u : rev_g[v]) {
		if (!css[u]) {
			dfs_css(u);
		}
	}
}

void build_css() {
	// Complexity: O(N+M)
	order.clear();
	fill(used, used + N, false);
	for (int v = 0; v < N; ++v) {
		if (!used[v]) {
			topsort(v);
		}
	}
	reverse(order.begin(), order.end());
	fill(css, css + N, 0);
	color = 1;
	for (int v : order) {
		if (!css[v]) {
			dfs_css(v);
			++color;
		}
	}
	// vertex colors are already in topsort order
}