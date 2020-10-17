#include <iostream>

using namespace std;

#define int long long

const int N = 1e5;

int n;
int fenw[N];

void add(int i, int x) {
  // Compexity: O(logN)
  for (; i < N; i = (i | i + 1)) {
    fenw[i] += x;
  }
}

int get(int i) {
  // Complexity: O(logN)
  int res = 0;
  for (; i >= 0; i = (i & i + 1) - 1) {
    res += fenw[i];
  }
  return res;
}

int get(int i, int j) {
  // Comlpexity: O(logN)
  return get(j) - get(i - 1);
}

// stresstest

struct Q {
  int x, y, z;
} q[N];

void gen_test() {
  n = 1e5;
  for (int i = 0; i < N; ++i) {
    if ((q[i].x = rand() % 2) == 0) {
      q[i].y = rand() % n;
      q[i].z = rand() % 3 + 1;
    } else {
      q[i].y = rand() % ((q[i].z = rand() % (n - 1)) + 1);
    }
  }
}

int a[N];

bool check() {
  fill(fenw, fenw + n, 0);
  fill(a, a + n, 0);
  for (int i = 0; i < N; ++i) {
    if (q[i].x == 0) {
      a[q[i].y] += q[i].z;
      add(q[i].y, q[i].z);
    } else {
      int res = 0;
      for (int j = q[i].y; j <= q[i].z; ++j) {
        res += a[j];
      }
      if (res != get(q[i].y, q[i].z)) {
        return false;
      }
    }
  }
  return true;
}

void stresstest() {
  int test_n = 1;
  while (true) {
    cout << "TEST #" << test_n++ << '\n';
    gen_test();
    if (!check()) {
      cout << "FAIL\n";
    } else {
      cout << "SUCCES\n";
    }
  }
}

signed main() { stresstest(); }
