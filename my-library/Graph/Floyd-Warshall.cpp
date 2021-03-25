#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 500;

int n;
int g[N][N];
int par[N][N];

void floyd_warshall() {
  const int INF = 1e9;
  for (int v = 0; v < n; ++v) {
    for (int u = 0; u < n; ++u) {
      par[v][u] = u;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int v = 0; v < n; ++v) {
      for (int u = 0; u < n; ++u) {
        if (g[v][u] > g[v][k] + g[k][u]) {
          g[v][u] = max(-INF, g[v][k] + g[k][u]);
          par[v][u] = par[v][k];
        }
      }
    }
  }
}
