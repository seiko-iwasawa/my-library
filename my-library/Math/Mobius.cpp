#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

int mu[N];
bool used[N];

void build_mu() {
  mu[1] = 1;
  vector<int> p;
  for (int i = 2; i < N; ++i) {
    if (!used[i]) {
      p.push_back(i);
      mu[i] = -1;
    }
    for (int j = 1; j < (int)p.size() && p[j] * i < N; ++j) {
      used[i * p[j]] = true;
      if (i % p[j]) {
        mu[i * p[j]] = -mu[i];
      } else {
        break;
      }
    }
  }
}