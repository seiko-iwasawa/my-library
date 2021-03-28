#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int n;
int a[N];

int dp[N + 1];

int build_lis() {
  int res = 0;
  dp[0] = -1;
  for (int i = 0; i < n; ++i) {
    int j = lower_bound(dp, dp + res + 1, i,
                        [&](int i, int j) { return i == -1 || a[i] < a[j]; }) -
            dp;
    dp[j] = i;
    res = max(res, j);
  }
  return res;
}
