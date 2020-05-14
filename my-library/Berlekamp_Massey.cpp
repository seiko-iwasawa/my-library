// unchecked

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long double ld;

const ld EPS = 1e-6;

template<class T>
vector<ld> Berlekamp_Massey(vector<T> seq) {
	// Complexity: O(len(res)**2 + len(seq))
	// 0 = sum res[j]*seq[i-j] for j = 0..len(res)-1
	vector<ld> res = { 1 };
	int i = -1;
	ld d = 1;
	vector<ld> _res = { 1 };
	int _i = -1;
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

int main() {
	vector<ld> seq = { 1, 3, 1, 2, 5.1, 2.9300000000000006, 7.0489999999999995, 7.645700000000001, 11.19201, 13.314793000000002, 20.3892049, 23.476064570000005, 35.120159201, 42.79055347930001 };
	vector<ld> res = Berlekamp_Massey(seq);
	cout << res.size() << '\n';
	for (ld x : res) {
		cout << x << ' ';
	}
	cout << '\n';
	system("pause");
}