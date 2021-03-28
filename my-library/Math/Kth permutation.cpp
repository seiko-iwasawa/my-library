#include <iostream>
#include <vector>

using namespace std;

vector<int> kth_permutation(int n, int k) {
  static vector<int> dp = {1};
  while (dp.size() <= n) {
    dp.push_back(dp.back() * dp.size());
  }
  vector<int> res;
  vector<char> used(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!used[j] && k > dp[n - 1 - i]) {
        k -= dp[n - 1 - i];
      } else if (!used[j]) {
        used[j] = true;
        res.push_back(j);
        break;
      }
    }
  }
  return res;
}
