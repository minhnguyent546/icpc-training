#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, k; cin >> n >> k;
	vector<vector<int>> num(k + 1, vector<int>());
	vector<int> color(n + 1);

	for (int i = 1; i <= n; i++) {
		int a, c; cin >> a >> c;
		color[i] = c;
		num[c].push_back(a);
	}

	for (int i = 1; i <= k; i++) {
		if (num[i].size())
			sort(num[i].begin(), num[i].end());
	}

	vector<int> pos(k + 1);
	int last = 0;

	for (int i = 1; i <= n; i++) {
		int cur = num[color[i]][pos[color[i]]++];
		if (cur < last) return !(cout << 'N');
		last = cur;
	}

	cout << 'Y';
}
