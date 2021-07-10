#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int N = 1e6 + 7;
const int A = 26;

struct Node {
  int nxt[A];
  int term;
  int par;
  int par_c;
  int go[A];
  int suf;
  int sup;

  Node() {
    fill(nxt, nxt + A, -1);
    term = 0;
    par = -1;
    par_c = -1;
    fill(go, go + A, -1);
    suf = -1;
    sup = -1;
  }
} trie[N];
int root = 0, sz_t = 1;

void add(string s) {
  int v = root;
  for (int i = 0; i < (int)s.size(); ++i) {
    s[i] -= 'a';
    if (trie[v].nxt[s[i]] == -1) {
      trie[v].nxt[s[i]] = sz_t;
      trie[sz_t] = Node();
      trie[sz_t].par = v;
      trie[sz_t].par_c = s[i];
      ++sz_t;
    }
    v = trie[v].nxt[s[i]];
  }
  ++trie[v].term;
}

vector<int> order;

void build() {
  order.clear();
  order.push_back(root);
  queue<int> q;
  for (int i = 0; i < A; ++i) {
    int u = trie[root].nxt[i];
    if (u != -1) {
      trie[root].go[i] = u;
      q.push(u);
    } else {
      trie[root].go[i] = root;
    }
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    order.push_back(v);
    if (trie[v].par == root) {
      trie[v].suf = root;
    } else {
      trie[v].suf = trie[trie[trie[v].par].suf].go[trie[v].par_c];
    }
    trie[v].sup =
        (trie[trie[v].suf].term ? trie[v].suf : trie[trie[v].suf].sup);
    for (int i = 0; i < A; ++i) {
      int u = trie[v].nxt[i];
      if (u != -1) {
        trie[v].go[i] = u;
        q.push(u);
      } else {
        trie[v].go[i] = trie[trie[v].suf].go[i];
      }
    }
  }
}

int go(string s) {
  int v = root;
  for (int i = 0; i < (int)s.size(); ++i) {
    v = trie[v].go[s[i] - 'a'];
  }
  return v;
}
