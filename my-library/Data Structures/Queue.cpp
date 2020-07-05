#include <iostream>
#include <cassert>

using namespace std;

const int N = 1e5;

int a[N], *first = a, *last = a;

int size() {
	return last - first;
}

bool empty() {
	return size() == 0;
}

void clear() {
	first = last = a;
}

void push(int x) {
	*last++ = x;
}

void pop() {
	assert(!empty());
	++first;
}

int front() {
	assert(!empty());
	return *first;
}
