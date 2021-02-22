#include <cassert>
#include <iostream>

using namespace std;

int rnd() { return rand() << 15 | rand(); }

struct Node *empty_node;

struct Node {
  int x, y;
  Node *L, *R;
  int sz = 0;
  long long sum = 0;

  int size() { return sz; }
  bool empty() { return !sz; }
  void upd() {
    if (!empty()) {
      sz = L->size() + 1 + R->size();
      sum = L->sum + x + R->sum;
    }
  }
  Node *kth(int k) {
    // Complexity: O(log(sz))
    assert(!empty());
    if (L->size() >= k) {
      return L->kth(k);
    } else if (L->size() == k - 1) {
      return this;
    } else {
      return R->kth(k - L->size() - 1);
    }
  }

  Node() {}
  Node(int _x) : x(_x), y(rnd()), L(empty_node), R(empty_node) { upd(); }
};

Node *merge(Node *q, Node *w) {
  if (q->empty()) {
    return w;
  } else if (w->empty()) {
    return q;
  } else if (q->y > w->y) {
    q->R = merge(q->R, w);
    q->upd();
    return q;
  } else {
    w->L = merge(q, w->L);
    w->upd();
    return w;
  }
}

pair<Node *, Node *> split(Node *t, int sx) {
  if (t->empty()) {
    return {empty_node, empty_node};
  } else if (t->x < sx) {
    auto st = split(t->R, sx);
    t->R = st.first;
    t->upd();
    return {t, st.second};
  } else {
    auto st = split(t->L, sx);
    t->L = st.second;
    t->upd();
    return {st.first, t};
  }
}

Node *insert(Node *t, int nx) {
  auto st = split(t, nx);
  return merge(merge(st.first, new Node(nx)), st.second);
}

Node *insert(Node *t, Node *nn) {
  auto st = split(t, nn->x);
  return merge(merge(st.first, nn), st.second);
}

Node *fast_insert(Node *t, Node *nn) {
  if (t->empty()) {
    return nn;
  } else if (t->y < nn->y) {
    auto st = split(t, nn->x);
    nn->L = st.first;
    nn->R = st.second;
    nn->upd();
    return nn;
  } else if (t->x < nn->x) {
    t->R = fast_insert(t->R, nn);
    t->upd();
    return t;
  } else {
    t->L = fast_insert(t->L, nn);
    t->upd();
    return t;
  }
}

Node *erase(Node *t, int ex) {
  auto st1 = split(t, ex);
  auto st2 = split(st1.second, ex);
  return merge(st1.first, st2.second);
}

// erased x should be exactly one in t
Node *fast_erase(Node *t, int ex) {
  if (t->x < ex) {
    t->R = fast_erase(t->R, ex);
    t->upd();
    return t;
  } else if (t->x == ex) {
    return merge(t->L, t->R);
  } else {
    t->L = fast_erase(t->L, ex);
    t->upd();
    return t;
  }
}

void solve() { empty_node = new Node; }
