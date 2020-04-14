// unchecked

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

#define int long long

int sum(int x, int y, int mod) { return x + y < mod ? x + y : x + y - mod; }
int mul(int x, int y, int mod) {
	int res = 0;
	while (y) {
		if (y & 1) {
			res = sum(res, x, mod);
		}
		x = sum(x, x, mod);
		y >>= 1;
	}
	return res;
}

mt19937 rnd(239);

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int pollard(int n) {
	if (n % 2 == 0) {
		return 2;
	}
	else if ((int)sqrt(n) * (int)sqrt(n) == n) {
		return sqrt(n);
	}
	else {
		auto nxt = [&](int seed) { return sum(mul(seed, seed, n), 3, n); };
		int x = rnd() % n;
		int y = x;
		for (int it = 0; it < 1e6; ++it) {
			if (x != y & gcd(abs(x - y), n) != 1) {
				return gcd(abs(x - y), n);
			}
			x = nxt(x);
			y = nxt(nxt(y));
		}
		return -1;
	}
}