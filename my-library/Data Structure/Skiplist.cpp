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

  vector<Node *> pref(int x) {
    vector<Node *> res;
    Node *cur = lvl[K - 1];
    while (cur != NULL) {
      while (cur->R != NULL && cur->R->x < x) {
        cur = cur->R;
      }
      res.push_back(cur);
      cur = cur->D;
    }
    reverse(res.begin(), res.end());
    return res;
  }

  Node *prev(int x) { return pref(x)[0]; }

  Node *find(int x) { return pref(x)[0]->R; }

  Node *next(int x) { return pref(x + 1)[0]->R; }

  int get_dp_pref(int x) {
    int res = 0;
    Node *cur = lvl[K - 1];
    while (cur != NULL) {
      while (cur->R != NULL && cur->R->x < x) {
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

  int get_ind(int x) {
    int ind = 0;
    Node *cur = lvl[K - 1];
    while (cur != NULL) {
      while (cur->R != NULL && cur->R->x < x) {
        ind += cur->sz;
        cur = cur->R;
      }
      if (cur->D == NULL) {
        ind += cur->sz;
      }
      cur = cur->D;
    }
    return ind;
  }

  int get_seg_dp(int x, int y) {}  // TODO

  int count(int x) { return get_ind(x + 1) - get_ind(x); }

  int kth(int k) {
    Node *cur = lvl[K - 1];
    while (true) {
      while (cur->R != NULL && k > cur->sz) {
        k -= cur->sz;
        cur = cur->R;
      }
      if (cur->D == NULL) {
        return cur->x;
      }
      cur = cur->D;
    }
  }

  void add(int x) {
    auto arr = pref(x);
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

  void del(int x) {
    auto arr = pref(x);
    for (int i = 0; i < K; ++i) {
      if (arr[i]->R != NULL && arr[i]->R->x == x) {
        arr[i]->R = arr[i]->R->R;
      }
      arr[i]->upd();
    }
  }

  Skiplist() {
    for (int i = 0; i < K; ++i) {
      lvl[i] = new Node(NULL, i == 0 ? NULL : lvl[i - 1], -INF);
    }
  }
};

pair<Skiplist, Skiplist> split(Skiplist a, int x) {
  auto arr = a.pref(x);
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
  auto arr = a.pref(INF);
  for (int i = 0; i < K; ++i) {
    arr[i]->R = b.lvl[i]->R;
    arr[i]->upd();
  }
}