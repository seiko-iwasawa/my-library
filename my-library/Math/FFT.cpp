#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

typedef complex<double> comp;

const double PI = atan2(0, -1);
const double EPS = 1e-6;
const int K = 20;
const int N = (1 << K);

int rev[N];
comp w[N];

void prepare() {
  for (int x = 0; x < N; ++x) {
    for (int i = 0; i < K; ++i) {
      rev[i] |= (x >> i & 1) << K - 1 - i;
    }
  }
  for (int i = 0; i < N; ++i) {
    w[i] = {cos(2 * PI * i / N), sin(2 * PI * i / N)};
  }
}

void fft(vector<comp> &a) {
  for (int i = 0; i < N; ++i) {
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int k = 2; k <= N; k <<= 1) {
    for (int s = 0; s < N; s += k) {
      for (int i = s; i < s + k / 2; ++i) {
        comp x = a[i], y = a[i + k / 2];
        a[i] = x + w[N * (i - s) / k] * y;
        a[i + k / 2] = x - w[N * (i - s) / k] * y;
      }
    }
  }
}

void inv_fft(vector<comp> &a) {
  fft(a);
  reverse(a.begin() + 1, a.end());
  for (int i = 0; i < N; ++i) {
    a[i] /= N;
  }
}