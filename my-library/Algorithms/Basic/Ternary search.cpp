#include <iostream>

using namespace std;

const int N = 1e5 + 7;

int n;
int a[N];

int get_max() {
  int left = 0, right = n;
  while (right - left > 1) {
    int len = right - left;
    int mid1 = left + len / 3;
    int mid2 = left + 2 * len / 3;
    if (a[mid1] > a[mid2]) {
      left = mid1;
    } else {
      right = mid2;
    }
  }
  return a[left];
}