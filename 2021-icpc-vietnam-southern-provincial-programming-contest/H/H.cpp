#include <bits/stdc++.h>

using namespace std;

// #undef LOCAL
#ifndef LOCAL
#define cerr if (false) cerr
#endif

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> f(n); 
	vector<int> par(n);
	auto dfs1 = [&](auto self, int u, int prev = -1) -> void {
		par[u] = prev;
		for (int v : g[u]) {
			if (v == prev) continue;
			self(self, v, u);
			f[u] = max(f[u], f[v] + 1);
		}
	};
	int root = 0;
	dfs1(dfs1, root);
	vector<int> h(n);
	auto dfs2 = [&](auto self, int u, int prev = -1) -> void {
		vector<int> left;
		for (int v : g[u]) {
			if (v == prev) left.push_back(h[u]);
			else left.push_back(f[v] + 1);
		}
		vector<int> right = left;
		for (int i = 1; i < (int) left.size(); ++i) {
			left[i] = max(left[i - 1], left[i]);
		}
		for (int i = (int) right.size() - 2; i >= 0; --i) {
			right[i] = max(right[i], right[i + 1]);
		}
		for (int i = 0; i < (int) g[u].size(); ++i) {
			int v = g[u][i];
			if (v == prev) continue;
			h[v] = h[u] + 1;
			if (i > 0) h[v] = max(h[v], left[i - 1] + 1);
			if (i + 1 < (int) g[u].size()) h[v] = max(h[v], right[i + 1] + 1);
		}
		for (int v : g[u]) {
			if (v == prev) continue;
			self(self, v, u);
		}
	};
	dfs2(dfs2, root);

	vector<vector<int>> all_f(n);
	for (int u = 0; u < n; ++u) {
		for (int v : g[u]) {
			if (v == par[u]) continue;
			all_f[u].push_back(f[v]);
		}
		sort(all_f[u].begin(), all_f[u].end());
	}
	for (int k = 0; k < m; ++k) {
		int u, t;
		cin >> u >> t;
		--u;
		int cnt = 0;
		cnt += (h[u] > t);
		auto it = lower_bound(all_f[u].begin(), all_f[u].end(), t) - all_f[u].begin();
		cnt += (int) all_f[u].size() - it;
		cout << cnt << '\n';
	}
	return 0;
}