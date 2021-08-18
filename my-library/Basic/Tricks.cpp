#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define ALL(c) c.begin(), c.end()
#define SZ(c) (int)c.size()

const int N = 1e4 + 7;

int n;
int a[N];
vector<int> arr(N);

void tricks() {
  fill(a, a + n, 7);
  iota(ALL(arr), 0);
  sort(ALL(arr), greater<int>());
  do {
    // ...
  } while (next_permutation(ALL(arr)));
  arr.erase(unique(ALL(arr)), arr.end());
  int shift = 10;
  rotate(a, a + shift, a + n);
  vector<int> a = {1, 2, 3}, b = {1, 3, 4};
  arr.clear();
  merge(ALL(a), ALL(b), back_inserter(arr));
  set<int> s(ALL(arr));
  if (s.count(1)) {
    cout << "1 exists\n";
  }
  const map<string, pair<int, int>> d = {{"left", {0, -1}},
                                         {"right", {0, +1}},
                                         {"up", {-1, 0}},
                                         {"down", {+1, 0}}};
  if (!d.count("go")) {
    cout << "the key does not exist\n";
  }
  auto cmp = [&](vector<int> x, vector<int> y) {
    return tie(x[1], x[0]) < tie(y[1], y[0]);
  };
}