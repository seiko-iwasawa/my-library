// unchecked

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int sum(int x, int y) { return x + y < MOD ? x + y : x + y - MOD; }
int dif(int x, int y) { return x - y < 0 ? x - y + MOD : x - y; }
int mul(int x, int y) { return x * 1LL * y % MOD; }
void add(int &x, int y) { x = sum(x, y); }
void sub(int &x, int y) { x = dif(x, y); }
int qp(int x, int k) {
	// Complexity: O(log(k))
	int res = 1;
	do {
		if (k & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
	} while (k >>= 1);
	return res;
}
int inv(int x) { return qp(x, MOD - 2); }
int dv(int x, int y) { return mul(x, inv(y)); }
vector<int> _fact = { 1 };
int fact(int x) {
	while (_fact.size() <= x) {
		_fact.push_back(mul(_fact.back(), _fact.size()));
	}
	return _fact[x];
}
int c(int n, int k) { return n < k ? 0 : dv(fact(n), mul(fact(k), fact(n - k))); }
