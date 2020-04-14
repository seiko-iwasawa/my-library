// unchecked

#include <iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void gcd_ext(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
	}
	else {
		gcd_ext(b, a % b, y, x);
		y -= a / b * x;
	}
}