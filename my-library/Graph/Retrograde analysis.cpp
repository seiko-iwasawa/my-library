#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 7;

int n;
vector<int> g[N], rev_g[N];

const int WIN = +1;
const int DRAW = 0;
const int LOSE = -1;

int deg[N];
int res[N];

void retrograde_analysis() {
  for (int v = 0; v < n; ++v) {
    deg[v] = g[v].size();
  }
  queue<int> q;
  for (int v = 0; v < n; ++v) {
    if (deg[v] == 0) {
      q.push(v);
      res[v] = LOSE;
    } else {
      res[v] = DRAW;
    }
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : rev_g[v]) {
      --deg[u];
      if (res[u] == DRAW) {
        if (res[v] == LOSE) {
          res[u] = WIN;
          q.push(u);
        } else if (deg[u] == 0) {
          res[u] = LOSE;
          q.push(u);
        }
      }
    }
  }
}