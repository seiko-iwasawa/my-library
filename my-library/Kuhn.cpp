// unchecked

#include <iostream>
#include <vector>

using namespace std;

const int N = 500;

vector<int> gL[N];

int pR[N];
int used[N], cnt;

bool dfs(int v) {
	used[v] = cnt;
	for (int u : gL[v]) {
		if (pR[u] == -1 || used[pR[u]] != cnt && dfs(pR[u])) {
			pR[u] = v;
			return true;
		}
	}
}

void kuhn() {
	// Complexity: O(N*M)
	fill(pR, pR + N, -1);
	cnt = 0;
	for (int v = 0; v < N; ++v, ++cnt) {
		dfs(v);
	}
}