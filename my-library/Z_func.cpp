// unchecked

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;

string s;
int zf[N];

void build_zf() {
	// Complexity: O(len(s))
	int n = s.size();
	fill(zf, zf + n, 0);
	for (int i = 1, l = 0, r = -1; i < n; ++i) {
		if (i < r) {
			zf[i] = min(r - i, zf[i - l]);
		}
		while (s[zf[i]] == s[i + zf[i]]) {
			++zf[i];
		}
		if (r < i + zf[i]) {
			l = i, r = i + zf[i];
		}
	}
}

int main() {
	s = "abcaabcab";
	build_zf();
}