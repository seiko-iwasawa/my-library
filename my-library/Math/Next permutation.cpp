#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// All elements must be a unique
vector<int> next_permutation(vector<int> arr) {
  if (arr.size() <= 1) {
    return arr;
  }
  int i = (int)arr.size() - 1;
  while (i > 0 && arr[i] < arr[i - 1]) {
    --i;
  }
  if (i == 0) {
    reverse(arr.begin(), arr.end());
    return arr;
  }
  int j = (int)arr.size() - 1;
  while (arr[j] < arr[i - 1]) {
    --j;
  }
  swap(arr[i - 1], arr[j]);
  reverse(arr.begin() + i, arr.end());
  return arr;
}
