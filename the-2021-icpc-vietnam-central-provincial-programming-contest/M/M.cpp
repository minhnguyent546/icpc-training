#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		// --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<bool> vis(n);
	auto dfs = [&](auto self, int u) -> int {
		int cnt = 1;
		vis[u] = true;
		for (int v : g[u]) {
			if (vis[v]) continue;
			cnt += self(self, v);
		}
		return cnt;
	};
	const int MOD = (int) 1e9 + 7;
	int res = 0;
	vector<int> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = 1LL * i * fact[i - 1] % MOD;
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			int comp = dfs(dfs, i);
			if (comp <= 2) continue;
			res += fact[comp];
			if (res >= MOD) res -= MOD;
		}
	}
	cout << res << '\n';
	return 0;
}