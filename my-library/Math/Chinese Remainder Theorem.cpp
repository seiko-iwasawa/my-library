#include <iostream>

using namespace std;

int gcd_ext(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int res = gcd_ext(b, a % b, y, x);
    y -= a / b * x;
    return res;
  }
}

int chreth(int n, int a, int m, int b) {
  int k1, k2;
  int d = gcd_ext(n, m, k1, k2);
  if ((b - a) % d != 0) {
    return -1;
  }
  int mod = n * m / d;
  int x = ((k1 * (b - a) / d * n + a) % mod + mod) % mod;
  return x;
}
