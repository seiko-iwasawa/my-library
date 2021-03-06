#include <iostream>

using namespace std;

const int N = 1e5;

const int A = 26;

struct Node {
  int go[A];
  int par;
  int par_c;
  int term;

  Node() {
    fill(go, go + A, -1);
    par = -1;
    par_c = -1;
    term = 0;
  }

  inline int& operator[](int c) { return go[c]; }
} trie[N];
int root = 0, t_sz = 0;

void add(string s) {
  int v = root;
  for (int i = 0; i < (int)s.size(); ++i) {
    s[i] -= 'a';
    if (trie[v][s[i]] == -1) {
      trie[t_sz].par = v;
      trie[t_sz].par_c = s[i];
      trie[v][s[i]] = t_sz;
      ++t_sz;
    }
    v = trie[v][s[i]];
  }
  ++trie[v].term;
}