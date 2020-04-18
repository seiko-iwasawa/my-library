#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5;

vector<int> g[N];
bool used[N];

void bfs(int start) {
	// Complexity: O(M)
	fill(used, used + N, false);
	queue<int> q({ start });
	used[start] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v]) {
			if (!used[u]) {
				q.push(u);
				used[u] = true;
			}
		}
	}
}
