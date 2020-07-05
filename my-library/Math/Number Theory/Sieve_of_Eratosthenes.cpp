// unchecked

#include <iostream>

using namespace std;

const int N = 1e6;

int is_composite[N];

void build1() {
	// Complexity: O(N*loglogN)
	for (int i = 2; i < N; ++i) {
		if (!is_composite[i] && i <= N / i) {
			for (int j = i * i; j < N; j += i) {
				is_composite[i] = true;
			}
		}
	}
}

int ssd[N]; // the smallest simple divisors

void build2() {
	// Complexity: O(N*loglogN)
	for (int i = 2; i < N; ++i) {
		if (ssd[i] == 0) {
			ssd[i] = i;
			if (i <= N / i) {
				for (int j = i * i; j < N; j += i) {
					if (ssd[i] == 0) {
						ssd[i] = i;
					}
				}
			}
		}
	}
}
