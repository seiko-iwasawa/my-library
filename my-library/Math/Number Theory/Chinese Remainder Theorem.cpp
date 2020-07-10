#include <iostream>

using namespace std;

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

/*
Returns min x>=0 such that x%n==a and x%m==b or -1 if none exist
Addiotional memory: O(1)
Time complexity: O(log(n+m))
*/
int chreth(int n, int a, int m, int b) {
	int k1, k2;
	int d = gcd_ext(n, m, k1, k2);
	if ((b - a) % d != 0) {
		return -1;
	}
	int mod = n * m / d;
	int x = ((k1 * (b - a) / d * n + a) % mod + mod) % mod;
	return x;
}

/*=================================STRESSTEST=================================*/

int n, a, m, b;

int stupid_solve(int n, int a, int m, int b) {
	int res = 0;
	while (res != n * m && (res % n != a || res % m != b)) {
		++res;
	}
	return res == n * m ? -1 : res;
}

void gen_test() {
#define SHOW_TEST
	n = rand() % 50 + 1;
	a = rand() % n;
	m = rand() % 50 + 1;
	b = rand() % m;
#ifdef SHOW_TEST
	cout << n << ' ' << a << ' ' << m << ' ' << b << '\n';
#endif
}

void stresstest() {
	int test_n = 1;
	while (true) {
		cout << "TEST #" << test_n++ << '\n';
		gen_test();
		if (chreth(n, a, m, b) != stupid_solve(n, a, m, b)) {
			cout << "FAIL\n";
			cout << "MY ANS: " << chreth(n, a, m, b) << '\n';
			cout << "RIGHT ANS: " << stupid_solve(n, a, m, b) << '\n';
			system("pause");
		}
		else {
			cout << "SUCCES\n";
		}
	}
}

int main() {
	stresstest();
}
