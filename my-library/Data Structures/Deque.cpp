#include <iostream>
#include <cassert>

using namespace std;

const int N = 1e5;

int deque[2 * N], *first = deque + N, *last = deque + N;

int size() {
	return last - first;
}

bool empty() {
	return size() == 0;
}

void clear() {
	first = last = deque + N;
}

void push_front(int x) {
	*--first = x;
}

void push_back(int x) {
	*last++ = x;
}

void pop_front() {
	++first;
}

void pop_back() {
	--last;
}

int front() {
	return *first;
}

int back() {
	return *(last - 1);
}
