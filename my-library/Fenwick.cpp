// unchecked

#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5;

int n;
ll fenw[N];

void add(int i, int x) {
	// Compexity: O(logN)
	for (; i < N; i = (i | i + 1)) {
		fenw[i] += x;
	}
}

ll get(int i) {
	// Complexity: O(logN)
	ll res = 0;
	for (; i >= 0; i = (i & i + 1) - 1) {
		res += fenw[i];
	}
	return res;
}

ll get(int i, int j) {
	// Comlpexity: O(logN)
	return get(j) - get(i - 1);
}