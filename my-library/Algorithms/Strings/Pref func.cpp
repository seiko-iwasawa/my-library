#include <iostream>

using namespace std;

const int N = 1e5;

string s;
int pf[N];

void build_pf() {
  // Complexity: O(len(s))
  for (int i = 1; i < s.size(); ++i) {
    int j = i - 1;
    while (j >= 0 && s[pf[j]] != s[i]) {
      j = pf[j] - 1;
    }
    pf[i] = (j == -1 ? 0 : pf[j] + 1);
  }
}
