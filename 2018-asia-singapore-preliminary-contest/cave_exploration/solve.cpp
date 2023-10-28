#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> num(n), low(n);
    int timer = 0;
    set<pair<int, int>> bridges;
    int dest = 0;
    auto dfs = [&](auto self, int u, int prev = -1) -> void {
        num[u] = low[u] = ++timer;
        for (int v : g[u]) {
            if (v == prev) continue;
            if (num[v]) low[u] = min(low[u], num[v]);
            else {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[v]) {
                    bridges.emplace(minmax(u, v));
                }
            }
        }
    };
    dfs(dfs, 0);
    vector<bool> vis(n);
    auto dfs2 = [&](auto self, int u) -> int {
        vis[u] = true;
        int cnt = 1;
        for (int v : g[u]) {
            if (vis[v] || bridges.count(minmax(u, v))) continue;
            cnt += self(self, v);
        }
        return cnt;
    };
    int res = dfs2(dfs2, dest);
    cout << res << '\n';


    return 0;
}
