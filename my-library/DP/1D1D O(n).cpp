#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int n;
int a[N];  // for each i < j: a[i] < a[j]
int b[N];  // for each i < j: b[i] > b[j]
ll dp[N];  // dp[i] = min dp[j] + a[j] * b[j]

void impl_1d1d() {
  auto w = [&](int j, int x) { return b[j] * 1LL * x; };
  auto divide = [&](int j, int i) { return (dp[i] - dp[j]) / (b[j] - b[i]); };
  dp[0] = 0;
  deque<pair<int, ll>> k = {{0, 0}};
  for (int i = 1; i < n; ++i) {
    while (k.size() >= 2 && k[1].second <= a[i]) {
      k.pop_front();
    }
    dp[i] = dp[k[0].first] + w(k[0].first, a[i]);
    if (i == n - 1) {
      break;
    }
    while (!k.empty() &&
           dp[k.back().first] + w(k.back().first, k.back().second) >=
               dp[i] + w(i, k.back().second)) {
      k.pop_back();
    }
    if (k.empty()) {
      k.push_back({i, i + 1});
    } else if (dp[k.back().first] + w(k.back().first, a[n - 1]) >=
               dp[i] + w(i, a[n - 1])) {
      k.push_back({i, divide(k.back().first, i)});
    }
  }
}