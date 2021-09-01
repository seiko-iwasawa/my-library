#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 1;

int phi[N];

void build_phi() {
  phi[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (phi[i] == 0) {
      phi[i] = i - 1;
      for (int j = i * min(i, N / i + 1); j < N; j += i) {
        phi[j] = i;
      }
      for (int j = i * min(i, N / i + 1); j < N; j += i * i) {
        phi[j] = -i;
      }
    } else if (phi[i] < 0) {
      phi[i] = phi[i / -phi[i]] * -phi[i];
    } else {
      phi[i] = phi[i / phi[i]] * (phi[i] - 1);
    }
  }
}