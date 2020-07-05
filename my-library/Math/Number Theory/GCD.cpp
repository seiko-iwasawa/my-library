#include <iostream>

using namespace std;

int gcd1(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd1(b, a % b);
	}
}

int gcd2(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int gcd3(int a, int b) {
	return b ? gcd3(b, a % b) : a;
}
