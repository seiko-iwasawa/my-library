// unchecked

// source of inspiration: http://acm.math.spbu.ru/~sk1/mm/lections/mipt2016-sqrt/solutions/E.OK.kthstat_sk.cpp.html

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5;
const int K = 400;
const int M = 2 * N / K + 7;

int n;
int a[N];

struct Block {
	int k;
	int *b;
	int delta;
	bool reversed;

	void reverse() {
		reversed ^= true;
	}

	void add(int x) {
		delta += x;
	}

	void simplify() {
		// Complexity: O(K)
		if (reversed) {
			std::reverse(b, b + k);
			reversed = false;
		}
		for (auto x = b; x < b + k; ++x) {
			*x += delta;
		}
		delta = 0;
	}

	void init(int *first, int _k) {
		// Complexity: O(K)
		k = _k;
		memcpy(b, first, k * sizeof(b[0]));
		reversed = false;
		delta = 0;
	}

	int operator[](int ind) {
		return b[(reversed ? k - 1 - ind : ind)] + delta;
	}

	Block() { b = new int[K]; }
} blocks[M];
int m;

void build() {
	// Complexity: O(N)
	m = 0;
	for (int i = 0; i < n; i += K, ++m) {
		blocks[m].init(a + i, min(K, n - i));
	}
}

void shift_right(int j) {
	// Complexity: O(M)
	for (int i = m; i > j; --i) {
		swap(blocks[i - 1], blocks[i]);
	}
	++m;
}

int split(int i) {
	// Complexity: O(M+K)
	if (i == n) {
		return m;
	}
	int j = 0;
	while (i >= blocks[j].k) {
		i -= blocks[j++].k;
	}
	if (i) {
		shift_right(j + 1);
		blocks[j].simplify();
		blocks[j + 1].init(blocks[j].b + i, blocks[j].k - i);
		blocks[j].init(blocks[j].b, i);
		return j + 1;
	}
	else {
		return j;
	}
}

void add(int i, int j, int delta) {
	// Complexity: O(M+K)
	for (int L = split(i), R = split(j); L < R; ++L) {
		blocks[L].add(delta);
	}
}

void reverse(int i, int j) {
	// Complexity: O(M+K)
	int L = split(i), R = split(j);
	reverse(blocks + L, blocks + R);
	for (; L < R; ++L) {
		blocks[L].reverse();
	}
}

int get(int i) {
	// Complexity: O(M)
	int j = 0;
	while (i >= blocks[j].k) {
		i -= blocks[j++].k;
	}
	return blocks[j][i];
}

void rebuild() {
	// Complexity: O(N)
	for (int i = 0, j = 0; i < n; i += blocks[j++].k) {
		blocks[j].simplify();
		memcpy(a + i, blocks[j].b, blocks[j].k * sizeof(a[0]));
	}
	build();
}
