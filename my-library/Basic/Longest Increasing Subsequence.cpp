#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int n;
int a[N];

int dp[N + 1];
int par[N];

int build_lis() {
  int res = 0;
  dp[0] = -1;
  for (int i = 0; i < n; ++i) {
    int j = lower_bound(dp, dp + res + 1, i,
                        [&](int i, int j) { return i == -1 || a[i] < a[j]; }) -
            dp;
    dp[j] = i;
    par[i] = dp[j - 1];
    res = max(res, j);
  }
  return res;
}

void print_ans(int i) {
  if (i != -1) {
    print_ans(par[i]);
    cout << a[i] << ' ';
  }
}

int main() {
  while (true) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int ans = build_lis();
    cout << ans << '\n';
    print_ans(dp[ans]);
    cout << '\n';
  }
}