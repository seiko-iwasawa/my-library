// unchecked

#include <iostream>
#include <numeric> // iota()

using namespace std;

const int N = 1e5;

int par[N], sz[N];

void build() {
	iota(par, par + N, 0);
	fill(sz, sz + N, 1);
}

int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		par[x] = y;
		sz[y] += sz[x];
	}
	return x != y;
}