#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int K = 16;
const int N = 2e5 / K + 7;
const int C = 77;
const int BASE = 1e16;

int n, m;
__int128 a[N], b[N], c[4 * N];

void stupid_mul(int la, int ra, int lb, int rb, int lc) {
  fill(c + lc, c + lc + ra - la + rb - lb - 1, 0);
  for (int i = la; i < ra; ++i) {
    for (int j = lb; j < rb; ++j) {
      c[lc + i - la + j - lb] += a[i] * b[j];
    }
  }
}

void mul(int la, int ra, int lb, int rb, int lc) {
  if (ra - la < C && rb - lb < C) {
    return stupid_mul(la, ra, lb, rb, lc);
  }
  /*
  (A+B*x**k)*(C+D*x**k) = A*C+(A*D+B*C)*x**k+B*D*x**2k =
  A*C+((A+B)*(C+D)-A*C-B*D)*x**k+B*D*x**2k
  */
  int sz = ra - la + rb - lb - 1;
  fill(c + lc, c + lc + sz, 0);
  int k = max(ra - la, rb - lb) >> 1;
  int sz1 = 2 * k - 1;
  mul(la, la + k, lb, lb + k, lc + sz);
  for (int i = 0; i < sz1; ++i) {
    c[lc + i] += c[lc + sz + i];
    c[lc + i + k] -= c[lc + sz + i];
  }
  if (ra - la >= k && rb - lb >= k) {
    int sz2 = sz - 2 * k;
    mul(la + k, ra, lb + k, rb, lc + sz);
    for (int i = 0; i < sz2; ++i) {
      c[lc + k + i] -= c[lc + sz + i];
      c[lc + 2 * k + i] += c[lc + sz + i];
    }
  }
  for (int i = 0; i < k; ++i) {
    a[la + k + i] += a[la + i];
    b[lb + k + i] += b[lb + i];
  }
  int sz3 = max(ra, la + 2 * k) - la + max(rb, lb + 2 * k) - lb - 2 * k - 1;
  mul(la + k, max(ra, la + 2 * k), lb + k, max(rb, lb + 2 * k), lc + sz);
  for (int i = 0; i < sz3; ++i) {
    c[lc + i + k] += c[lc + sz + i];
  }
  for (int i = 0; i < k; ++i) {
    a[la + k + i] -= a[la + i];
    b[lb + k + i] -= b[lb + i];
  }
}

void print(long long x, int d) {
  if (d) {
    print(x / 10, d - 1);
    cout << x % 10;
  }
}

void solve() {
  string sa, sb;
  cin >> sa >> sb;
  n = sa.size(), m = sb.size();
  for (int i = n - 1; i >= 0; --i) {
    a[i / K] = a[i / K] * 10 + sa[n - 1 - i] - '0';
  }
  for (int j = m - 1; j >= 0; --j) {
    b[j / K] = b[j / K] * 10 + sb[m - 1 - j] - '0';
  }
  n = (n + K - 1) / K, m = (m + K - 1) / K;
  mul(0, n, 0, m, 0);
  fill(c + n + m - 1, c + 4 * N, 0);
  int sz = 1;
  for (int i = 0; i < 4 * N - 1; ++i) {
    c[i + 1] += c[i] / BASE;
    if ((c[i] %= BASE) != 0) {
      sz = i + 1;
    }
  }
  cout << (long long)c[sz - 1];
  for (int i = sz - 2; i >= 0; --i) {
    print(c[i], K);
  }
  cout << '\n';
}
