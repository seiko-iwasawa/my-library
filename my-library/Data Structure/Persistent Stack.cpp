#include <cassert>
#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int par[N] = {-1};
int val[N];
int cnt = 1;

void push(int v, int x) {
  par[cnt] = v;
  val[cnt] = x;
  ++cnt;
}

void pop(int v) {
  assert(par[v] != -1);
  par[cnt] = par[par[v]];
  val[cnt] = val[par[v]];
  ++cnt;
}

int back(int v) { return val[v]; }