#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5;
const int C = 77;

int n, m;
int a[N], b[N], c[4 * N];

void stupid_mul(int la, int ra, int lb, int rb, int lc) {
  // Complexity: O(n*m)
  fill(c + lc, c + lc + ra - la + rb - lb - 1, 0);
  for (int i = la; i < ra; ++i) {
    for (int j = lb; j < rb; ++j) {
      c[lc + i - la + j - lb] += a[i] * b[j];
    }
  }
}

void mul(int la, int ra, int lb, int rb, int lc) {
  // Complexity: O((n+m)**log2(3))
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
