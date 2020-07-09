#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <string>
#include <cassert>

using namespace std;

int sign(int x) {
	return x < 0 ? -1 : +1;
}

const int BASE = 10;

struct BI : vector<int> {
	int sign;

	// Only works for BASE == 10
	void init(string x) {
		clear();
		if (x[0] == '-') {
			sign = -1;
			x.erase(x.begin());
		}
		else {
			sign = +1;
		}
		for (int i = x.size() - 1; i >= 0; --i) {
			push_back(x[i] - '0');
		}
	}

	void init(int x) {
		clear();
		if (x < 0) {
			sign = -1;
			x = -x;
		}
		else {
			sign = +1;
		}
		do {
			push_back(x % BASE);
		} while (x /= BASE);
	}

	BI() { sign = +1, push_back(0); }

	BI(string x) { init(x); }

	BI(int x) { init(x); }

	BI(vector<int> x) {
		for (int d : x) {
			init(d);
		}
	}
};

auto to_tuple(BI a) {
	return make_tuple(a.sign, a.size(), vector<int>(a.rbegin(), a.rend()));
}

// Only works for BASE == 10
istream& operator>>(istream &in, BI &a) {
	string x;
	in >> x;
	a = BI(x);
	return in;
}

// Onle works for BASE == 10**k
ostream& operator<<(ostream &out, BI a) {
	if (a.sign == -1) {
		cout << '-';
	}
	for (int i = (int)a.size() - 1; i >= 0; --i) {
		out << a[i];
	}
	return out;
}

bool operator==(BI a, BI b) {
	return to_tuple(a) == to_tuple(b);
}

bool operator!=(BI a, BI b) {
	return !(a == b);
}

bool operator<(BI a, BI b) {
	return a != b && a.sign <= b.sign && (to_tuple(a) < to_tuple(b) ^ b.sign == -1);
}

bool operator>(BI a, BI b) {
	return b < a;
}

bool operator<=(BI a, BI b) {
	return a < b || a == b;
}

bool operator>=(BI a, BI b) {
	return b <= a;
}

BI operator-(BI a) {
	a.sign = -a.sign;
	return a;
}

BI normalize(BI a) {
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] >= BASE) {
			if (i + 1 == a.size()) {
				a.push_back(0);
			}
			a[i + 1] += a[i] / BASE;
			a[i] %= BASE;
		}
		else if (a[i] < 0) {
			--a[i + 1];
			a[i] += BASE;
		}
	}
	while (!a.empty() && a.back() == 0) {
		a.pop_back();
	}
	if (a.empty()) {
		a.sign = +1;
		a.push_back(0);
	}
	return a;
}

BI operator-(BI a, BI b);

BI operator+(BI a, BI b) {
	if (a < b) {
		swap(a, b);
	}
	if (b < 0) {
		return a - (-b);
	}
	else {
		for (int i = 0; i < b.size(); ++i) {
			a[i] += b[i];
		}
		return normalize(a);
	}
}

BI operator-(BI a, BI b) {
	if (a < b) {
		return -(b - a);
	}
	if (b < 0) {
		return a + (-b);
	}
	else {
		for (int i = 0; i < b.size(); ++i) {
			a[i] -= b[i];
		}
		return normalize(a);
	}
}

BI operator*(BI a, int x) {
	a.sign *= sign(x);
	for (int i = 0; i < a.size(); ++i) {
		a[i] *= abs(x);
	}
	return normalize(a);
}

BI operator*(int x, BI a) {
	return a * x;
}

BI operator*(BI a, BI b) {
	BI res;
	res.sign = a.sign * b.sign;
	res.resize(a.size() + b.size() - 1);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			res[i + j] += a[i] * b[j];
		}
	}
	return normalize(res);
}

BI operator/(BI a, int x) {
	assert(x != 0);
	BI res;
	res.resize(a.size());
	res.sign = a.sign * sign(x);
	for (int i = a.size() - 1; i >= 0; --i) {
		res[i] = a[i] / x;
		a[i] %= x;
		if (i != 0) {
			a[i - 1] += a[i] * BASE;
			a[i] = 0;
		}
	}
	res = normalize(res);
	a = normalize(a);
	if (a < 0) {
		return res - sign(x);
	}
	else if (a >= x) {
		return res + sign(x);
	}
	else {
		return res;
	}
}

BI operator/(BI a, BI b) {
	assert(b != 0);
	BI left = -a * a.sign - 1, right = a * a.sign + 1;
	while (right - left > 1) {
		BI mid = (left + right) / 2;
		(a < mid * b ^ b.sign == -1 ? right : left) = mid;
	}
	return left + (b.sign == -1);
}

BI operator%(BI a, BI b) {
	return a - a / b * b;
}

BI& operator+=(BI &a, BI b) {
	return a = a + b;
}

BI& operator-=(BI &a, BI b) {
	return a = a - b;
}

BI& operator*=(BI &a, int x) {
	return a = a * x;
}

BI& operator/=(BI &a, int x) {
	return a = a / x;
}

BI& operator/=(BI &a, BI b) {
	return a = a / b;
}

BI& operator%=(BI &a, BI b) {
	return a = a % b;
}

BI sqrt(BI x) {
	assert(x >= 0);
	BI left = 0, right = x;
	while (right - left > 1) {
		BI mid = (left + right) / 2;
		(mid * mid <= x ? left : right) = mid;
	}
	return left;
}

/*=================================STRESSTEST=================================*/

int my_dv(int a, int b) {
	assert(b != 0);
	int d = (b < 0 ? -1 : +1);
	int res = a / b - d;
	while (a >= b * (res + d)) {
		res += d;
	}
	return res;
}

void test_sum(int a, int b) {
	if (a + b != BI(a) + BI(b)) {
		cout << "wrong sum: " << a << ' ' << b << '\n';
		cout << a + b << '\n';
		cout << BI(a) + BI(b) << '\n';
		system("pause");
	}
}

void test_dif(int a, int b) {
	if (a - b != BI(a) - BI(b)) {
		cout << "wrong dif: " << a << ' ' << b << '\n';
		cout << a - b << '\n';
		cout << BI(a) - BI(b) << '\n';
		system("pause");
	}
}

void test_mul(int a, int b) {
	if (a * b != BI(a) * BI(b)) {
		cout << "wrong mul: " << a << ' ' << b << '\n';
		cout << a * b << '\n';
		cout << BI(a) * BI(b) << '\n';
		system("pause");
	}
}

void test_dv(int a, int b) {
	if (b != 0 && my_dv(a, b) != BI(a) / BI(b)) {
		cout << "wrong dv: " << a << ' ' << b << '\n';
		cout << my_dv(a, b) << '\n';
		cout << BI(a) / BI(b) << '\n';
		system("pause");
	}
}

void test(int a, int b) {
	test_sum(a, b);
	test_dif(a, b);
	test_mul(a, b);
	test_dv(a, b);
}

void test_output() {
	cout << BI(0) << '\n';
	cout << BI("123") << '\n';
	cout << BI(-2233112) << '\n';
}

void random_test() {
	const int T = 1000;
	const int C = 10000;
	for (int t = 0; t < T; ++t) {
		int a = rand() % (2 * C) - C;
		int b = rand() % (2 * C) - C;
		test(a, b);
	}
}

void make_all_small_tests() {
	const int C = 15;
	for (int a = -C; a <= C; ++a) {
		for (int b = -C; b <= C; ++b) {
			test(a, b);
		}
	}
}

void stresstest() {
	test_output();
	random_test();
	make_all_small_tests();
}

int main() {
	stresstest();
	return 0;
}