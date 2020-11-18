#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 1;
const int K = 18;  // K is equal to floor(log2(N)).

int f(int a, int b) {
  // Complexity: O(F). In this case, O(1).
  /*
  The operation requires only associativity[1], commutativity[2] and
  idempotency[3]. For example: min, max, gcd.
  --------------------------
  [1] - associativity: f(a, f(b, c)) = f(f(a, b), c)
  [2] - commutativity: f(a, b) = f(b, a)
  [3] - idempotency: f(a, a) = a
  */
  return min(a, b);
}

// Memory: O(N*logN).
int n, arr[N];
int lg[N];     // array for precalc of floor(log2(r - l))
int st[N][K];  // sparse table: st[i][k] = f(arr[i], arr[i + 1], ..., arr[i + 2
               // ^ k - 1])

void build_lg() {
  // Complexity: O(N).
  lg[0] = -1;
  for (int i = 1; i < N; ++i) {
    lg[i] = lg[i / 2] + 1;
  }
}

void build_st() {
  // Complexity: O(N*logN*F).
  /*
  to start:
  f(a[i]) = a[i]
  */
  for (int i = 0; i < n; ++i) {
    st[i][0] = arr[i];
  }

  /*
  st[i][k] = f(a[i], a[i + 1], ..., a[i + 2 ^ k - 1]) =

  = f(f(a[i], ..., a[i + 2 ^ (k - 1) - 1]), f(a[i + 2 ^ (k - 1)], ..., a[i + 2 ^
  k - 1])) =

  = f(st[i][k - 1], st[i + 2 ^ (k - 1)][k - 1])
  */
  for (int k = 1; k < K; ++k) {
    for (int i = 0; i + (1 << k) <= n; ++i) {
      st[i][k] = f(st[i][k - 1], st[i + (1 << k - 1)][k - 1]);
    }
  }
}

void build() {
  build_lg();
  build_st();
}

int get(int l, int r) {
  // Complexity: O(F).
  /*
  return f(arr[l], arr[l + 1], ..., arr[r - 1])
  <IMPORTANT>This request is for the semi-interval [l, r)! Also, l <
  r.</IMPORTANT>
  */

  /*
  Denote k = lg[r - l].
  Notice, that
  f(arr[l], arr[l + 1], ..., arr[r - 1]) =
  = f(f(arr[l], ..., arr[l + 2 ^ k - 1]), f(arr[r - 2 ^ k], ..., arr[r - 1])),
  'cause [l, l + 2 ^ k - 1] and [r - 2 ^ k, r - 1] in [l, r) and this segments
  cover all semi-interval [l, r).

  f(arr[l], ..., arr[l + 2 ^ k - 1]) = st[l][k]
  f(arr[r - 2 ^ k], ..., arr[r - 1]) = st[r - 2 ^ k][k]
  So, f(arr[l], arr[l + 1], ..., arr[r - 1]) = f(st[l][k], st[r - 2 ^ k][k]).
  */
  int k = lg[r - l];
  return f(st[l][k], st[r - (1 << k)][k]);
}
