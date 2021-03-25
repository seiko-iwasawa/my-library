#include <cassert>
#include <iostream>

using namespace std;

const int N = 1e5;

int n;
int a[N];

int lower_bound(int x) {
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = l + r >> 1;
    (a[mid] < x ? l : r) = mid;
  }
  return r;
}

const double EPS = 1e-9;

double sqrt(int x) {
  assert(x >= 0);
  double l = 0, r = x;
  while (r - l > EPS) {
    double mid = (l + r) / 2;
    (mid * mid <= x ? l : r) = mid;
  }
  return l;
}
