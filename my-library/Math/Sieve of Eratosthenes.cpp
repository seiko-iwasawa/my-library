#include <iostream>

using namespace std;

const int N = 1e6;

int d[N];  // d[x] is the smallest 1<d<x such that x|d

void build() {
  for (int i = 2; i < N; ++i) {
    if (d[i] == 0) {
      d[i] = i;
      if (i <= N / i) {
        for (int j = i * i; j < N; j += i) {
          if (d[j] == 0) {
            d[j] = i;
          }
        }
      }
    }
  }
}
