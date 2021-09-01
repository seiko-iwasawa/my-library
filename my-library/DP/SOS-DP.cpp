#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
int s[1 << N];   // stores the initial value for each set
int dp[1 << N];  // stores the sum over subsets

void calc_sos() {
  copy(s, s + (1 << N), dp);
  for (int i = 0; i < N; ++i) {
    for (int mask = 0; mask < (1 << N); ++mask) {
      if (mask >> i & 1) {
        dp[mask] += dp[mask ^ 1 << i];
      }
    }
  }
}