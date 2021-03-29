#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
finds min for lines (kx+b) for a given 'x'
u can add lines in non-increasing order of the 'k'
*/
struct CHT {
  vector<pair<int, int>> line;  // contains stack of the lines as pair (k, b)
  vector<double> p;             // points of intersections nearby lines in stack

  double intersect(pair<int, int> n, pair<int, int> m) {
    return (double)(m.second - n.second) / (n.first - m.first);
  }

  void add_line(int k, int b) {
    if (line.empty()) {
      line.push_back({k, b});
      return;
    }
    if (line.back().first == k) {
      if (line.back().second >= b) {
        return;
      } else {
        line.pop_back();
        if (!line.empty()) {
          p.pop_back();
        } else {
          line.push_back({k, b});
          return;
        }
      }
    }
    while (line.size() > 1 && p.back() >= intersect(line.back(), {k, b})) {
      line.pop_back();
      p.pop_back();
    }
    p.push_back(intersect(line.back(), {k, b}));
    line.push_back({k, b});
  }

  int get_min(int x) {
    auto n = lower_bound(line.begin(), line.end(), x);
    return n->first * x + n->second;
  }

  CHT() {}
};