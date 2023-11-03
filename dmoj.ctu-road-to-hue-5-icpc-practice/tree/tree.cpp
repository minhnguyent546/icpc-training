/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct SegTree {
	int n;
	vector<long long> tree;
	SegTree() {}
	SegTree(int _n): n(_n) {
		tree.resize(n * 2);
	}
	void assign(int i, long long val) {
		tree[i += n] = val;
		for (i /= 2; i > 0; i /= 2) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	}
	long long query(int l, int r) {
		long long res = 0;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) res += tree[l++];
			if (r & 1) res += tree[--r];
		}
		return res;
	}
};

struct HLD {
	int n;
	vector<vector<int>> g;
	SegTree segtree;
	vector<int> par, top, depth, sz, id;
	int timer = 0;
	int root = 0;
	HLD() {}
	HLD(int _n): n(_n), g(n), segtree(n), par(n), top(n), depth(n), sz(n), id(n) {}
	void build() {
		dfs_sz(root);
		dfs_hld(root);
	}
	void add_edge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}
	void dfs_sz(int u) {
		sz[u] = 1;
		for (int &v : g[u]) {
			par[v] = u;
			depth[v] = depth[u] + 1;
			g[v].erase(find(g[v].begin(), g[v].end(), u));
			dfs_sz(v);
			sz[u] += sz[v];
			if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
		}
	}
	void dfs_hld(int u) {
		id[u] = timer++;
		for (int v : g[u]) {
			top[v] = (v == g[u][0] ? top[u] : v);
			dfs_hld(v);
		}
	}
	void set_edge(int u, int v, int w) {
		if (u != par[v]) swap(u, v);
		segtree.assign(id[v], w);
	}
	long long dist(int u, int v) {
		if (u == v) return 0;
		long long res = 0;
		while (top[u] != top[v]) {
			if (depth[top[u]] > depth[top[v]]) swap(u, v);
			res += segtree.query(id[top[v]], id[v]);
			v = par[top[v]];
		}
		if (depth[u] > depth[v]) swap(u, v);
		res += segtree.query(id[u] + 1, id[v]);
		return res;
	}

};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
	vector<array<int, 3>> edges(n - 1);
	HLD hld(n);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	--u;
    	--v;
    	hld.add_edge(u, v);
    	edges[i] = {u, v, w};
    }
    hld.build();
    for (auto [u, v, w] : edges) {
    	hld.set_edge(u, v, w);
    }
    int q;
    cin >> q;
    for (int w = 0; w < q; ++w) {
    	int op;
    	cin >> op;
    	if (op == 1) {
    		int i, w;
    		cin >> i >> w;
    		--i;
    		hld.set_edge(edges[i][0], edges[i][1], w);
    	}
    	else if (op == 2) {
    		int u, v;
    		cin >> u >> v;
    		--u; --v;
    		cout << hld.dist(u, v) << '\n';
    	}
    	else assert(false);
    }

	return 0;
}
