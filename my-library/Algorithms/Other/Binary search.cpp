#include <iostream>
#include <cassert>

using namespace std;

const int N = 1e5;

int n;
int a[N];

/*
Returns min i=0..n-1, such that a[i] >= x in sorted array a or n if it does not exist
Additional memory: O(1)
Time complexity: O(log(n))
*/
int lower_bound(int x) {
	int l = -1, r = n;
	while (r - l > 1) {
		int mid = l + r >> 1;
		(a[mid] < x ? l : r) = mid;
	}
	return r;
}

const double EPS = 1e-9;

/*
Returns y such that x==y*y±EPS
x must be non-negative
Additional memory: O(1)
Time complexity: O(log(x/EPS))
*/
double sqrt(int x) {
	assert(x >= 0);
	double l = 0, r = x;
	while (r - l > EPS) {
		double mid = (l + r) / 2;
		(mid * mid <= x ? l : r) = mid;
	}
	return l;
}
