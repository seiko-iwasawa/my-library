// unchecked

#include <iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int gcd_ext(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int res = gcd_ext(b, a % b, y, x);
		y -= a / b * x;
		return res;
	}
}

int chreth(int n, int a, int m, int b) {
	/*
	return min x >= 0 such that
	x % n == a
	x % m == b
	*/
	int k1, k2;
	int d = gcd_ext(n, m, k1, k2);
	if (abs(b - a) % d != 0) {
		return -1;
	}
	int mod = n * m / d;
	int x = ((k1 * n + a) % mod + mod) % mod;
	return x;
}