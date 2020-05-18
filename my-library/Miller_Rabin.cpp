// unchecked

#include <iostream>
#include <random>

using namespace std;

#define int long long

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int sum(int a, int b, int mod) {
	return a + b < mod ? a + b : a + b - mod;
}

int mul(int a, int b, int mod) {
	int res = 0;
	do {
		if (b & 1) {
			res = sum(res, a, mod);
		}
		a = sum(a, a, mod);
	} while (b >>= 1);
	return res;
}

int qp(int a, int k, int mod) {
	int res = 1;
	do {
		if (k & 1) {
			res = mul(res, a, mod);
		}
		a = mul(a, a, mod);
	} while (k >>= 1);
	return res;
}

bool miller_rabin_test(int a, int n) {
	if (a >= n) {
		return true;
	}
	if (gcd(a, n) != 1) {
		return false;
	}
	int m = n - 1;
	while (~(m >>= 1) & 1) {
		if (qp(a, m, n) == n - 1) {
			return true;
		}
	}
	return qp(a, m, n) == n - 1 || qp(a, m, n) == 1;
}

bool is_prime(int n) {
	if (n == 1) {
		return false;
	}
	else if (n % 2 == 0) {
		return n == 2;
	}
	else {
		for (int a : {2, 3, 5, 7, 11, 13, 17, 19}) {
			if (!miller_rabin_test(a, n)) {
				return false;
			}
		}
		mt19937 rnd(239);
		for (int it = 0; n >> it; ++it) {
			if (!miller_rabin_test(rnd() % (n - 1) + 1, n)) {
				return false;
			}
		}
		return true;
	}
}

signed main() {
	while (true) {
		int n;
		cin >> n;
		cout << (is_prime(n) ? "YES\n" : "NO\n");
	}
}