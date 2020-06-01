// unchecked

#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 777777773;
const int P = 239;

int sum(int x, int y, int mod) { return x + y < mod ? x + y : x + y - mod; }
int dif(int x, int y, int mod) { return x - y < 0 ? x - y + mod : x - y; }
int mul(int x, int y, int mod) { return x * 1LL * y % mod; }

struct Hash {
	int h1, h2;
};

bool operator==(Hash a, Hash b) { return a.h1 == b.h1 && a.h2 == b.h2; }
Hash operator+(Hash a, Hash b) { return { sum(a.h1, b.h1, MOD1), sum(a.h2, b.h2, MOD2) }; }
Hash operator-(Hash a, Hash b) { return { dif(a.h1, b.h1, MOD1), dif(a.h2, b.h2, MOD2) }; }
Hash operator*(Hash a, Hash b) { return { mul(a.h1, b.h1, MOD1), mul(a.h2, b.h2, MOD2) }; }
Hash operator*(Hash h, int x) { return { mul(h.h1, x, MOD1), mul(h.h2, x, MOD2) }; }

Hash p[N];

void build_p() {
	p[0] = { 1, 1 };
	for (int i = 1; i < N; ++i) {
		p[i] = p[i - 1] * P;
	}
}

string s;
Hash pref[N];

void build_pref() {
	pref[0] = { 0, 0 };
	for (int i = 1; i <= s.size(); ++i) {
		pref[i] = pref[i - 1] * P + Hash({ s[i - 1], s[i - 1] });
	}
}

Hash get_substr_hash(int i, int j) {
	return pref[j] - pref[i] * p[j - i];
}

int main() {
	build_p();
	cin >> s;
	build_pref();
}
