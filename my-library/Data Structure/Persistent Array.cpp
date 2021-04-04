#include <iostream>

using namespace std;

// used files: Persistent Segment Tree.cpp

const int N = 1e5 + 7;

struct Node {
  int x;
  int l, r;
  Node *L, *R;

  int size() { return r - l; }
  bool have(int i) { return l <= i && i < r; }

  Node() {}
  Node(int _x, int i) : x(_x), l(i), r(i + 1), L(NULL), R(NULL) {}
  Node(Node *_L, Node *_R) : L(_L), R(_R) {}
} tree[N];

Node *upd(Node *t, int i, int x) {
  if (!t->have(i)) {
    return t;
  } else if (t->size() == 1) {
    return new Node(x, i);
  } else {
    return new Node(upd(t->L, i, x), upd(t->R, i, x));
  }
}

int get(Node *t, int ql, int qr) {
  if (t->r <= ql || qr <= t->l) {
    return 0;
  } else if (ql <= t->l && t->r <= qr) {
    return t->x;
  } else {
    return get(t->L, ql, qr) + get(t->R, ql, qr);
  }
}
