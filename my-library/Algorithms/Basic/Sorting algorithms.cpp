#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <random>

using namespace std;

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

void unstable_selection_sort() {
  for (int i = 0; i < n; ++i) {
    swap(a[i], *min_element(a + i, a + n));
  }
}

// TODO stable_selection_sort, quick_sort, radix_sort

void heap_sort() {
  make_heap(a, a + n);
  for (int i = 0; i < n; ++i) {
    pop_heap(a, a + n - i);
  }
}

namespace merge_sort {

vector<int> merge_sort1(vector<int> arr) {
  if (arr.size() == 1) {
    return arr;
  } else {
    vector<int> res;
    vector<int> left_part =
        merge_sort1({arr.begin(), arr.begin() + arr.size() / 2});
    vector<int> right_part =
        merge_sort1({arr.begin() + arr.size() / 2, arr.end()});
    merge(left_part.begin(), left_part.end(), right_part.begin(),
          right_part.end(), back_inserter(res));
    return res;
  }
}

int new_a[N];

void merge_sort2() {
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n;) {
      // b == begin, e == end
      int b1 = i, e1 = min(n, i + k);
      int b2 = e1, e2 = min(n, i + 2 * k);
      while (b1 != e1 || b2 != e2) {
        if (b2 != e2 && (b1 == e1 || a[b2] < a[b1])) {
          new_a[i++] = a[b2++];
        } else {
          new_a[i++] = a[b1++];
        }
      }
    }
    swap(a, new_a);
  }
}

void merge_sort3() {
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      inplace_merge(a + i, a + min(n, i + k), a + min(n, i + 2 * k));
    }
  }
}
}  // namespace merge_sort

namespace counting_sort {

const int A = 1000;

vector<int> cnt[A];
int ptr[A];

void clear() {
  fill(ptr, ptr + A, 0);
  for (int i = 0; i < A; ++i) {
    cnt[i].clear();
    cnt[i].shrink_to_fit();
  }
}

void counting_sort() {
  clear();
  for (int i = 0; i < n; ++i) {
    cnt[a[i]].push_back(a[i]);
  }
  for (int i = 0, x = 0; x < A; ++x) {
    for (; ptr[x] < cnt[x].size(); ++ptr[x]) {
      a[i++] = cnt[x][ptr[x]];
    }
  }
}
}  // namespace counting_sort

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
