/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    int root = 0;
    vector<int> w;
    int n = 1;
    vector<vector<int>> g(q);
    for (int i = 0; i < q; ++i) {
    	int type, u;
    	cin >> type >> u;
    	--u;
    	if (type == 1) {
    		int v = n++;
    		g[u].push_back(v);
    	}
    	else {
    		w.push_back(u);
    	}
    }
    vector<int> tin(n);
    int timer = 0;
    auto dfs = [&](auto self, int u) -> void {
    	tin[u] = timer++;
    	for (int v : g[u]) {
    		self(self, v);
    	}
    };
    dfs(dfs, root);
    set<pair<int, int>> s;
    // for (int i = 0; i < n; ++i) {
    // 	cerr << i << ' ' << tin[i] << '\n';
    // }
    for (int i = 0; i < n; ++i) {
    	s.emplace(tin[i], i);
    }
    int cur_king = root;
    for (auto &u : w) {
    	// cerr << "die: " << u << ' ' << tin[u] << '\n';
    	s.erase({tin[u], u});
    	if (u == cur_king) {
    		cur_king = s.begin()->second;
    	}
    	cout << cur_king + 1 << '\n';
    }
	return 0;
}
