// unchecked

#include <iostream>
#include <bitset>
#include <cassert>

using namespace std;

const int N = 1e3;

bitset<N + 1> eq[N];
bool used[N];
bitset<N + 1> ans;

bool check_ans() {
	for (int i = 0; i < N; ++i) {
		if ((ans & eq[i]).count() != eq[i][N]) {
			return false;
		}
	}
	return true;
}

void gauss_mod2() {
	// Complexity: O(N**3/64)
	for (int i = 0; i < N; ++i) {
		int j;
		for (j = 0; j < N && (used[j] || !eq[j][i]); ++j);
		if (j != N) {
			used[j] = true;
			for (int k = 0; k < N; ++k) {
				if (k != j && eq[k][i]) {
					eq[k] ^= eq[j];
				}
			}
		}
	}
	ans = 0;
	for (int i = 0; i < N; ++i) {
		int j;
		for (j = 0; j < N && !eq[i][j]; ++j);
		if (j != N) {
			ans[j] = eq[i][N];
		}
	}
	assert(check_ans());
}
