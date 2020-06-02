#include <iostream>

using namespace std;

const int N = 1e5;

int n;
int a[N];

int my_solve() {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (ans == a[i]);
	}
	return ans;
}

int stupid_solve() {
	for (int x = 0; x <= n; ++x) {
		if (find(a, a + n, x) == a + n) {
			return x;
		}
	}
	return -1;
}

void gen_test() {
//#define SHOW_TEST
	n = rand() % 5 + 1;
	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 5;
	}
#ifdef SHOW_TEST
	cout << n << '\n';
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
#endif
}

void clear_all() {
	fill(a, a + n, 0);
}

void stresstest() {
	int test_n = 1;
	while (true) {
		cout << "TEST #" << test_n++ << '\n';
		gen_test();
		if (my_solve() != stupid_solve()) {
			cout << "FAIL\n";
			cout << "MY ANS: " << my_solve() << '\n';
			cout << "RIGHT ANS: " << stupid_solve() << '\n';
			system("pause");
		}
		else {
			cout << "SUCCES\n";
		}
		clear_all();
	}
}

int main() {
	stresstest();
}