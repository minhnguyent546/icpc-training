#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int BIT = 31;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<array<int ,2>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    };
    vector<vector<int>> grs(n);
    vector<bool> vis(n);
    vector<int> h(n);
    int cnt = 0;
    auto dfs = [&](auto self, int u, int prev = -1) -> void {
        grs[cnt].push_back(u);
        vis[u] = true;
        for (auto [v, w] : g[u]) {
            if (v == prev) continue;
            if (vis[v]) {
                if ((h[u] ^ w) != h[v]) {
                    cout << -1 << '\n';
                    exit(0);
                }
            }
            else {
                h[v] = h[u] ^ w;
                self(self, v, u);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(dfs, i);
            ++cnt;
        }
    }
    long long res = 0;
    for (int k = 0; k < cnt; ++k) {
        vector<int> ones(BIT);
        int sz = (int) grs[k].size();
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < BIT; ++j) {
                if (h[grs[k][i]] & (1 << j)) {
                    ones[j]++;
                }
            }
        }
        long long cur = 0;
        for (int i = 0; i < BIT; ++i) {
            int mn = min(ones[i], sz - ones[i]);
            cur += (long long) mn << i;
        }
        res += cur;
    }
    cout << res << '\n';

    return 0;
}
