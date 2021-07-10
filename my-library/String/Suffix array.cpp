#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 2e5 + 7;

int n;
string s;
int sufa[N], back;

int eqcl[N];
int nxt_eqcl[N];
vector<int> cnt[N];

// sorts cyclic shifts
void build_sufa() {
  for (int i = 0; i < n; ++i) {
    eqcl[i] = s[i];
    cnt[eqcl[i]].push_back(i);
  }
  back = 0;
  for (int c = 0; c < N; ++c) {
    for (int j : cnt[c]) {
      sufa[back++] = j;
    }
    cnt[c].clear();
  }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; ++i) {
      cnt[eqcl[(sufa[i] - k + n) % n]].push_back((sufa[i] - k + n) % n);
    }
    back = 0;
    for (int c = 0; c < N; ++c) {
      for (int j : cnt[c]) {
        sufa[back++] = j;
      }
      cnt[c].clear();
    }
    nxt_eqcl[sufa[0]] = 0;
    for (int i = 0; i + 1 < n; ++i) {
      if (eqcl[sufa[i]] == eqcl[sufa[i + 1]] &&
          eqcl[(sufa[i] + k) % n] == eqcl[(sufa[i + 1] + k) % n]) {
        nxt_eqcl[sufa[i + 1]] = nxt_eqcl[sufa[i]];
      } else {
        nxt_eqcl[sufa[i + 1]] = nxt_eqcl[sufa[i]] + 1;
      }
    }
    swap(eqcl, nxt_eqcl);
  }
}