#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 300 + 1;

int n;
int c[N][N];
int ans_row[N], ans_col[N];
int d_row[N], d_col[N];
bool ok_row[N], ok_col[N];
int col_min[N];

inline int get(int i, int j) {
	return c[i][j] + d_row[i] + d_col[j];
}

int get_ans() {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += c[i][ans_row[i]];
	}
	return res;
}

int main() {
	freopen("assignment.in", "r", stdin);
	freopen("assignment.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> c[i][j];
		}
	}
	fill(ans_row, ans_row + n, -1);
	fill(ans_col, ans_col + n, -1);
	for (int k = 0; k < n; ++k) {
		fill(ok_col, ok_col + n, true);
		vector<int> ir = { k };
		for (int j = 0; j < n; ++j) {
			col_min[j] = k;
		}
		vector<int> cur_ans_col(n, -1);
		while (true) {
			int bi = -1, bj = -1;
			for (int j = 0; j < n; ++j) {
				if (ok_col[j]) {
					int i = col_min[j];
					if (bi == -1 || get(bi, bj) > get(i, j)) {
						bi = i;
						bj = j;
					}
				}
			}
			int new_row = ans_col[bj];
			cur_ans_col[bj] = bi;
			int mn = c[bi][bj] + d_row[bi] + d_col[bj];
			for (int i : ir) {
				d_row[i] -= mn;
			}
			for (int j = 0; j < n; ++j) {
				if (!ok_col[j]) {
					d_col[j] += mn;
				}
			}
			ok_col[bj] = false;
			if (new_row != -1) {
				for (int j = 0; j < n; ++j) {
					if (ok_col[j]) {
						if (get(col_min[j], j) > get(new_row, j)) {
							col_min[j] = new_row;
						}
					}
				}
				ir.push_back(new_row);
			}
			else {
				int v = bj;
				while (v != -1) {
					int i = cur_ans_col[v];
					int j = v;
					v = ans_row[i];
					ans_row[i] = j;
					ans_col[j] = i;
				}
				break;
			}
		}
	}
	cout << get_ans() << '\n';
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ' ' << ans_row[i] + 1 << '\n';
	}
	//system("pause");
	return 0;
}