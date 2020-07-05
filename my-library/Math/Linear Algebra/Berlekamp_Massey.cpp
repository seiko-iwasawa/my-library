#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long double ld;

const ld EPS = 1e-3;

template<class T>
vector<ld> Berlekamp_Massey(vector<T> seq) {
	// Complexity: O(len(res)**2 + len(seq))
	// 0 = sum res[j]*seq[i-j] for j = 0..len(res)-1
	vector<ld> res = { 1 };
	int i = 0;
	ld d = 1;
	vector<ld> _res = { 1 };
	int _i = 0;
	ld _d = 1;
	for (i = 0; i < seq.size(); ++i) {
		d = 0;
		for (int j = 0; j < res.size(); ++j) {
			d += res[j] * seq[i - j];
		}
		if (abs(d) > EPS) {
			vector<ld> tmp_res = res;
			res.resize(max((int)res.size(), (int)_res.size() + i - _i));
			auto at = [&](int j) { return j < 0 || j >= _res.size() ? 0 : _res[j]; };
			for (int j = 0; j < res.size(); ++j) {
				res[j] -= d / _d * at(j - (i - _i));
			}
			_res = tmp_res;
			_i = i;
			_d = d;
		}
	}
	return res;
}

// stresstest

#define int long long

vector<int> originally_r;
vector<int> seq;

template<class T>
int get(int i, vector<T> &r) {
	T res = 0;
	for (int j = 0; j < r.size(); ++j) {
		res += r[j] * seq[i - j];
	}
	return res;
}

void gen_test() {
//#define SHOW_TEST
	originally_r.resize(rand() % 4 + 3);
	for (int &x : originally_r) {
		x = rand() % 4 - 2;
	}
	originally_r[0] = 1;
	seq.resize(originally_r.size() - 1);
	for (int &x : seq) {
		x = rand() % 4 + 1;
	}
	for (int i = 0; i < 7; ++i) {
		seq.push_back(0);
		seq.back() = -get(i + originally_r.size() - 1, originally_r);
	}
#ifdef SHOW_TEST
	for (int x : seq) {
		cout << x << ' ';
	}
	cout << '\n';
	for (int x : originally_r) {
		cout << x << ' ';
	}
	cout << '\n';
#endif
}

bool check(vector<ld> &r) {
	for (int i = r.size(); i < seq.size(); ++i) {
		if (abs(get(i, r)) > EPS) {
			return false;
		}
	}
	return true;
}

void stresstest() {
	int test_n = 1;
	while (true) {
		cout << "TEST #" << test_n++ << '\n';
		gen_test();
		vector<ld> r = Berlekamp_Massey(seq);
		if (r.size() > originally_r.size() || !check(r)) {
			cout << "FAIL\n";
			cout << "MY ANS: ";
			for (ld x : r) {
				cout << x << ' ';
			}
			cout << '\n';
			cout << "RIGHT ANS: ";
			for (int x : originally_r) {
				cout << x << ' ';
			}
			cout << '\n';
			system("pause");
		}
		else {
			cout << "SUCCES\n";
		}
	}
}

signed main() {
	cout.precision(6); cout << fixed;
	stresstest();
	vector<ld> seq = { 3, 3, 3, -3, 15, -33 };
	vector<ld> res = Berlekamp_Massey(seq);
	cout << res.size() << '\n';
	for (ld x : res) {
		cout << x << ' ';
	}
	cout << '\n';
	system("pause");
}
