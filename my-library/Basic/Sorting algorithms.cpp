#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

mt19937 rnd(7);

const int N = 1e5;

int n;
int a[N];

void std_sort() { sort(a, a + n); }

void std_stable_sort() { stable_sort(a, a + n); }

void bubble_sort() {
  for (int it = 0; it < n; ++it) {
    for (int i = 0; i < n - 1; ++i) {
      if (a[i + 1] < a[i]) {
        swap(a[i], a[i + 1]);
      }
    }
  }
}

void insertion_sort() {
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j && a[j] < a[j - 1]) {
      swap(a[j - 1], a[j]);
      --j;
    }
  }
}

void selection_sort() {
  for (int i = 0; i < n; ++i) {
    swap(a[i], *min_element(a + i, a + n));
  }
}

void quick_sort(int l, int r) {
  if (r - l <= 1 || count(a + l, a + r, a[l]) == r - l) {
    return;
  }
  int x = a[rnd() % n];
  int mid = l;
  for (int i = l; i < r; ++i) {
    if (a[i] <= x) {
      swap(a[mid], a[i]);
      ++mid;
    }
  }
  quick_sort(l, mid - 1);
  quick_sort(mid, r);
}

void heap_sort() {
  make_heap(a, a + n);
  for (int i = 0; i < n; ++i) {
    pop_heap(a, a + n - i);
  }
}

void merge_sort() {
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      inplace_merge(a + i, a + min(n, i + k), a + min(n, i + 2 * k));
    }
  }
}

namespace counting_sort {

const int A = 1000;

vector<int> cnt[A];

void counting_sort() {
  for (int i = 0; i < n; ++i) {
    cnt[a[i]].push_back(a[i]);
  }
  for (int i = 0, x = 0; x < A; ++x) {
    for (int j = 0; j < cnt[x].size(); ++j) {
      a[i++] = cnt[x][j];
    }
  }
}
}  // namespace counting_sort

void radix_sort() {
  const int D = 10;
  int mx = *max_element(a, a + n);
  vector<int> cnt[D];
  for (int k = 1; k < mx; k *= D) {
    for (int i = 0; i < n; ++i) {
      cnt[a[i] / k % D].push_back(i);
    }
    for (int i = 0, x = 0; x < D; ++x) {
      for (int j = 0; j < cnt[x].size(); ++j) {
        a[i++] = cnt[x][j];
      }
      cnt[x].clear();
    }
  }
}

namespace fast_sort {

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
  clear();
  for (int i = 0; i < n; ++i) {
    cnt[a[i] & SZ - 1].push_back(a[i]);
  }
  for (int i = 0, x = 0; x < SZ; ++x) {
    for (; ptr[x] < cnt[x].size(); ++ptr[x]) {
      a[i++] = cnt[x][ptr[x]];
    }
  }
  for (int i = 0; i < n; ++i) {
    cnt[a[i] >> K].push_back(a[i]);
  }
  for (int i = 0, x = 0; x < SZ; ++x) {
    for (; ptr[x] < cnt[x].size(); ++ptr[x]) {
      a[i++] = cnt[x][ptr[x]];
    }
  }
}
}  // namespace fast_sort
