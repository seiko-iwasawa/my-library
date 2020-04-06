// unchecked

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

	int operator[](int i) {
		if (L->sz < i) {
			return (*L)[i];
		}
		else if (L->sz == i) {
			return x;
		}
		else {
			return (*R)[i - L->sz - 1];
		}
	}

	Node() {}
	Node(int _x) : x(_x), y(rnd()), L(empty_node), R(empty_node) { upd(); }
};

Node* merge(Node *q, Node *w) {
	// Complexity: O(log(size_q)+log(size_w))
	if (q->empty()) {
		return w;
	}
	else if (w->empty()) {
		return q;
	}
	else if (q->y < w->y) {
		q->R = merge(q->R, w);
		q->upd();
		return q;
	}
	else {
		w->L = merge(q, w->L);
		w->upd();
		return w;
	}
}

pair<Node*, Node*> split(Node *t, int k) {
	// Complexity: O(log(size_t))
	if (t->empty()) {
		return { empty_node, empty_node };
	}
	else if (t->size() < k) {
		auto st = split(t->R, k - t->size());
		t->R = st.first;
		t->upd();
		return { t, st.second };
	}
	else {
		auto st = split(t->L, k);
		t->L = st.second;
		t->upd();
		return { st.first, t };
	}
}

int main() {
	empty_node = new Node;
}
