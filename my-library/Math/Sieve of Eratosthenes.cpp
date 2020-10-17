#include <iostream>

using namespace std;

const int N = 1e6;

int d[N];  // d[x] is the smallest 1<d<x such that x|d

/*
Build array d
x > 0 and d[x]==x <=> x is prime
Additional memory: O(1)
Time complexity: O(N*loglogN)
*/
void build() {
  for (int i = 2; i < N; ++i) {
    if (d[i] == 0) {
      d[i] = i;
      if (i <= N / i) {  // i*i can be overflow
        for (int j = i * i; j < N; j += i) {
          if (d[i] == 0) {
            d[i] = i;
          }
        }
      }
    }
  }
}
