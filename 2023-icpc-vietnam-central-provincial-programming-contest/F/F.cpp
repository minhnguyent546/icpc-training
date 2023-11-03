#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int LOG = 21;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	map<pair<int, int>, pair<int, int>> edges;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges[{min(u, v), max(u, v)}] = {a, b};
	}
	vector<vector<int>> anc(LOG, vector<int>(n, -1));
	vector<int> depth(n);

	auto dfs1 = [&](auto self, int u, int prev = -1) -> void {
		anc[0][u] = prev;
		for (int v : g[u]) {
			if (v == prev) continue;
			depth[v] = depth[u] + 1;
			self(self, v, u);
		}
	};
	dfs1(dfs1, 0);
	for (int j = 1; j < LOG; ++j) {
		for (int i = 0; i < n; ++i) {
			anc[j][i] = (anc[j - 1][i] != -1 ? anc[j - 1][anc[j - 1][i]] : -1);
		}
	}
	auto get_lca = [&](int u, int v) {
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];
		for (int i = 0; i < LOG; ++i) {
			if (diff & (1  << i)) {
				u = anc[i][u];
			}
		}
		if (u == v) return u;
		for (int i = LOG - 1; i >= 0; --i) {
			int pu = anc[i][u];
			int pv = anc[i][v];
			if (pu != pv) {
				u = pu;
				v = pv;
			}
		}
		assert(anc[0][u] == anc[0][v]);
		return anc[0][u];
	};	
	vector<int> val(n);
	for (int i = 0; i < n - 1; ++i) {
		int lca = get_lca(i, i + 1);
		val[i]++;
		val[i + 1]++;
		val[lca] -= 2;
	}
	map<pair<int, int>, long long> f;
	auto dfs2 = [&](auto self, int u, int prev = -1) -> long long {
		long long x = val[u];
		for (int v : g[u]) {
			if (v == prev) continue;
			long long y = self(self, v, u);
			f[{min(u, v), max(u, v)}] = y;
			x += y;
		}
		return x;
	};
	dfs2(dfs2, 0);
	long long res = 0;
	for (auto [uv, cnt] : f) {
		auto [u, v] = uv;
		res += min(1LL * cnt * edges[{u, v}].first, 1LL * edges[{u, v}].second);
	}
	cout << res << '\n';
	return 0;
}