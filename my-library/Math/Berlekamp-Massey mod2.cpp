#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Berlekamp_Massey_mod2(vector<int> seq) {
  vector<int> res = {1};
  int i = 0;
  int d = 1;
  vector<int> _res = {1};
  int _i = 0;
  int _d = 1;
  for (i = 0; i < seq.size(); ++i) {
    d = 0;
    for (int j = 0; j < res.size(); ++j) {
      d ^= res[j] & seq[i - j];
    }
    if (d != 0) {
      vector<int> tmp_res = res;
      res.resize(max((int)res.size(), (int)_res.size() + i - _i));
      auto at = [&](int j) { return j < 0 || j >= _res.size() ? 0 : _res[j]; };
      for (int j = 0; j < res.size(); ++j) {
        res[j] -= at(j - (i - _i));
      }
      _res = tmp_res;
      _i = i;
      _d = d;
    }
  }
  return res;
}
