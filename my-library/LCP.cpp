#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int N = 2e5 + 7;

int p[N], c[N], pn[N], cn[N];

int cnt[N];

int lcp[N];

int n;

void build_lcp(string s) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		int x = c[i];
		int j = p[x - 1];
		while (s[i + k] == s[j + k]) k++;
		lcp[x] = k;
		k = max(k - 1, 0);
	}
}

void cnt_sort() {
	fill(cnt, cnt + N, 0);
	for (int i = 0; i < n; i++)
		cnt[c[i]]++;
	for (int i = n - 1; i > 0; i--)
		cnt[i] = cnt[i - 1];
	cnt[0] = 0;
	for (int i = 1; i < n; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++) {
		pn[cnt[c[p[i]]]] = p[i];
		cnt[c[p[i]]]++;
	}
	for (int i = 0; i < n; i++)
		p[i] = pn[i];
}

void build(string s) {
	n = s.size();
	vector<pair<char, int>> a(n);
	for (int i = 0; i < n; i++)
		a[i] = { s[i], i };
	sort(a.begin(), a.end());
	p[0] = a[0].second;
	c[p[0]] = 0;
	for (int i = 1; i < n; i++) {
		p[i] = a[i].second;
		if (a[i].first == a[i - 1].first)
			c[p[i]] = c[p[i - 1]];
		else
			c[p[i]] = c[p[i - 1]] + 1;
	}
	int k = 0;
	while ((1 << k) < n) {
		for (int i = 0; i < n; i++)
			p[i] = (p[i] - (1 << k) + n) % n;
		cnt_sort();
		cn[p[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (make_pair(c[p[i]], c[(p[i] + (1 << k)) % n]) == make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]))
				cn[p[i]] = cn[p[i - 1]];
			else
				cn[p[i]] = cn[p[i - 1]] + 1;
		}
		for (int i = 0; i < n; i++)
			c[i] = cn[i];
		k++;
	}
	build_lcp(s);
}

int main() {
	string s; cin >> s;
	s += "$";
	build(s);
	for (int i = 1; i < s.size(); i++)
		cout << p[i] << " ";
	cout << endl;
	for (int i = 1; i < s.size(); i++)
		cout << lcp[i] << " ";
	return 0;
}
