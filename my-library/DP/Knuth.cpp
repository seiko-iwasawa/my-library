#include <iostream>
#include <tuple>

using namespace std;

const int N = 5007;
const int INF = 1e9 + 7;

int n;
int a[N];
int pref[N];
// dp[i][j] = a[i] + ... + a[j] + min dp[i][k - 1] + dp[k + 1][j] - a[k]
int dp[N][N];
int opt[N][N];

int knuth() {
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
    opt[i][i] = i;
    pref[i + 1] = pref[i] + a[i];
  }
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len - 1 < n; ++i) {
      int j = i + len - 1;
      dp[i][j] = INF;
      for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; ++k) {
        tie(dp[i][j], opt[i][j]) = min(
            make_tuple(dp[i][j], opt[i][j]),
            make_tuple(
                pref[j + 1] - pref[i] + dp[i][k - 1] + dp[k + 1][j] - a[k], k));
      }
    }
  }
}