// unchecked

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

// min-heap
struct Heap {
	vector<int> heap;

	int size() { return heap.size(); }

	void sift_down(int i) {
		// Complexity: O(log(size))
		while (2 * i + 1 < size()) {
			int child = 2 * i + 1;
			if (2 * i + 2 < size() && heap[2 * i + 2] < heap[2 * i + 1]) {
				child = 2 * i + 2;
			}
			if (heap[child] < heap[i]) {
				swap(heap[i], heap[child]);
				i = child;
			}
			else {
				break;
			}
		}
	}

	void sift_up(int i) {
		// Complexity: O(log(size))
		while (heap[i] < heap[(i - 1) / 2]) {
			swap(heap[i], heap[(i - 1) / 2]);
			--i /= 2;
		}
	}

	int top() {
		// Complexity: O(1)
		return heap[0];
	}

	void pop() {
		// Complexity: O(log(size))
		heap[0] = heap.back();
		heap.pop_back();
		sift_down(0);
	}

	void push(int x) {
		// Complexity: O(log(size))
		heap.push_back(x);
		sift_up(size() - 1);
	}

	void build() {
		// Complexity: O(size*log(size))
		for (int i = 0; i < size(); ++i) {
			sift_up(i);
		}
	}

	void fast_build() {
		// Complexity: O(size)
		for (int i = size() / 2; i >= 0; --i) {
			sift_down(i);
		}
	}

	Heap() {}
	Heap(vector<int> &a) : heap(a) { fast_build(); }
};

Heap merge(Heap a, Heap b) {
	// Complexity: O(size_b*log(size_a+size_b))
	for (int x : b.heap) {
		a.push(x);
	}
	return a;
}

Heap fast_merge(Heap a, Heap b) {
	// Complexity: O(size_a+size_b)
	for (int x : b.heap) {
		a.heap.push_back(x);
	}
	a.fast_build();
	return a;
}

int kth_min_elem(Heap a, int k) {
	// Complexity: O(k*log(size_a))
	while (--k) {
		a.top();
		a.pop();
	}
	return a.top();
}