#include <iostream>
#include <algorithm>
#include <queue>
#include <random>
#include <ctime>

using namespace std;

const int N = 1e5;

int a[N];

void std_sort() {
	// Complexity: O(N*logN)
	// Unstable
	sort(a, a + N);
}

void bubble_sort() {
	// Complexity: O(N**2)
	// Stable
	for (int _ = 0; _ < N; ++_) {
		for (int i = 0; i < N - 1; ++i) {
			if (a[i + 1] < a[i]) {
				swap(a[i], a[i + 1]);
			}
		}
	}
}

void insertion_sort() {
	// Complexity: O(N**2)
	// Stable
	for (int i = 0; i < N; ++i) {
		int j = i;
		while (j && a[j] < a[j - 1]) {
			swap(a[j - 1], a[j]);
			--j;
		}
	}
}

void unstable_selection_sort() {
	// Complexity: O(N**2)
	// Unstable
	for (int i = 0; i < N; ++i) {
		swap(a[i], *min_element(a + i, a + N));
	}
}

void heap_sort() {
	// Complexity: O(N*logN)
	// Additional memory: O(N)
	priority_queue<int, vector<int>, greater<int>> heap(a, a + N);
	for (int i = 0; i < N; ++i) {
		a[i] = heap.top();
		heap.pop();
	}
}

namespace QUICK_SORT {
	// TODO
}

namespace MERGE_SORT {
	vector<int> merge_sort1(vector<int> arr) {
		// Complexity: O(N*logN)
		// Additional memory: O(N+logN)
		// Stable
		if (arr.size() == 1) {
			return arr;
		}
		else {
			vector<int> res;
			vector<int> left_part = merge_sort1({ arr.begin(), arr.begin() + arr.size() / 2 });
			vector<int> right_part = merge_sort1({ arr.begin() + arr.size() / 2, arr.end() });
			merge(left_part.begin(), left_part.end(), right_part.begin(), right_part.end(), back_inserter(res));
			return res;
		}
	}

	int b[N];

	void merge_sort2() {
		// Complexity: O(N*logN)
		// Additional memory: O(N)
		// Stable
		for (int ss = 1; ss < N; ss *= 2) {
			for (int i = 0; i < N;) {
				int b1 = i;
				int e1 = min(N, i + ss);
				int b2 = min(N, i + ss);
				int e2 = min(N, i + 2 * ss);
				while (b1 != e1 || b2 != e2) {
					if (b2 != e2 && (b1 == e1 || a[b2] < a[b1])) {
						b[i++] = a[b2++];
					}
					else {
						b[i++] = a[b1++];
					}
				}
			}
			swap(a, b);
		}
	}

	void merge_sort3() {
		// Complexity: O(N*logN)
		// Stable
		for (int ss = 1; ss < N; ss *= 2) {
			for (int i = 0; i < N; i += 2 * ss) {
				inplace_merge(a + i, a + min(N, i + ss), a + min(N, i + 2 * ss));
			}
		}
	}
}

namespace FAST_SORT {
	// a[i] < 4**K

	const int K = 15;
	const int SZ = 1 << K;

	vector<int> cnt[SZ];
	int ptr[SZ];

	void clear() {
		fill(ptr, ptr + SZ, 0);
		for (int i = 0; i < SZ; ++i) {
			cnt[i].clear();
			cnt[i].shrink_to_fit();
		}
	}

	void fast_sort() {
		// Complexity: O(N + 2**K)
		// Additional memory: O(N + 2**K)
		// Stable
		for (int i = 0; i < N; ++i) {
			cnt[a[i] & SZ - 1].push_back(a[i]);
		}
		for (int i = 0, x = 0; x < SZ; ++x) {
			for (; ptr[x] < cnt[x].size(); ++ptr[x]) {
				a[i++] = cnt[x][ptr[x]];
			}
		}
		for (int i = 0; i < N; ++i) {
			cnt[a[i] >> K].push_back(a[i]);
		}
		for (int i = 0, x = 0; x < SZ; ++x) {
			for (; ptr[x] < cnt[x].size(); ++ptr[x]) {
				a[i++] = cnt[x][ptr[x]];
			}
		}
	}
}

mt19937 rnd(239);

//#define SHOW_TEST

void gen_test() {
	const int MAX_A = 1e9;
	for (int i = 0; i < N; ++i) {
		a[i] = rnd() % MAX_A;
#ifdef SHOW_TEST
		cout << a[i] << ' ';
#endif
	}
#ifdef SHOW_TEST
	cout << '\n';
#endif
}

bool check() {
	for (int i = 0; i < N - 1; ++i) {
		if (a[i + 1] < a[i]) {
			return false;
		}
	}
	return true;
}

void stresstest() {
	int test_n = 1;
	while (true) {
		cout << "TEST #" << test_n++ << '\n';
		gen_test();
		int start = clock();
		MERGE_SORT::merge_sort3();
		int finish = clock();
		if (check()) {
			cout << "SUCCES: " << finish - start << "ms\n";
		}
		else {
			cout << "FAIL\n";
			system("pause");
		}
	}
}

int main() {
	stresstest();
	return 0;
}