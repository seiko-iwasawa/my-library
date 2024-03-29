#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 3e5 + 7;
const int K = 20;
const int INF = 1e9 + 7;

struct Skiplist {
  struct Node {
    Node *R, *D;
    int dp, x, sz;

    void upd() {
      if (D == NULL) {
        dp = x;
        sz = 1;
      } else {
        Node *cur = D;
        dp = 0;
        sz = 0;
        while (cur != NULL && (R == NULL || cur != R->D)) {
          dp += cur->dp;
          sz += cur->sz;
          cur = cur->R;
        }
      }
    }

    Node(Node *R, Node *D, int x) : R(R), D(D), x(x) { upd(); }
  };

  Node *lvl[K];

  vector<Node *> pref(int sz) {
    vector<Node *> res;
    Node *cur = lvl[K - 1];
    while (cur != NULL) {
      while (cur->sz < sz) {
        sz -= cur->sz;
        cur = cur->R;
      }
      res.push_back(cur);
      cur = cur->D;
    }
    reverse(res.begin(), res.end());
    return res;
  }

  int size() {
    int sz = 0;
    Node *cur = lvl[K - 1];
    while (cur != NULL) {
      sz += cur->sz;
      cur = cur->R;
    }
    return sz;
  }

  Node *prev(int sz) { return pref(sz)[0]; }

  Node *find(int sz) { return pref(sz)[0]->R; }

  Node *next(int sz) { return pref(sz + 1)[0]->R; }

  int get_dp_pref(int sz) {
    int res = 0;
    Node *cur = lvl[K - 1];
    while (cur != NULL) {
      while (cur->sz < sz) {
        sz -= cur->sz;
        res += cur->dp;
        cur = cur->R;
      }
      if (cur->D == NULL) {
        res += cur->dp;
      }
      cur = cur->D;
    }
    return res;
  }

  int get_val(int sz) {
    int ind = 0;
    Node *cur = lvl[K - 1];
    while (cur != NULL) {
      while (cur->sz < sz) {
        sz -= cur->sz;
        cur = cur->R;
      }
      if (cur->D == NULL) {
        return cur->x;
      }
      cur = cur->D;
    }
  }

  int get_seg_dp(int x, int y) {}  // TODO

  void add(int x, int sz) {
    auto arr = pref(sz);
    arr[0]->R = new Node(arr[0]->R, NULL, x);
    int i = 1;
    while (i < K && rand() % 2) {
      arr[i]->R = new Node(arr[i]->R, arr[i - 1]->R, x);
      ++i;
    }
    for (int j = 0; j < K; ++j) {
      arr[j]->upd();
      if (j < i) {
        arr[j]->R->upd();
      }
    }
  }

  void del(int sz) {}  // TODO

  Skiplist() {
    for (int i = 0; i < K; ++i) {
      lvl[i] = new Node(NULL, i == 0 ? NULL : lvl[i - 1], -INF);
    }
  }
};

pair<Skiplist, Skiplist> split(Skiplist a, int sz) {
  auto arr = a.pref(sz);
  Skiplist b;
  for (int i = 0; i < K; ++i) {
    if (arr[i] != NULL) {
      b.lvl[i]->R = arr[i]->R;
      b.lvl[i]->upd();
      arr[i]->R = NULL;
      arr[i]->upd();
    }
  }
  return {a, b};
}

void merge(Skiplist a, Skiplist b) {
  auto arr = a.pref(a.size());
  for (int i = 0; i < K; ++i) {
    arr[i]->R = b.lvl[i]->R;
    arr[i]->upd();
  }
}