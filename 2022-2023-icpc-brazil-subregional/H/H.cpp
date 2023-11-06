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
        --u; --v;
        g[u].push_back(v);
    }
    vector<int> num(n), low(n), stack;
    vector<int> scc_id(n);
    vector<bool> used(n);
    int timer = 0, scc = 0;
    auto dfs = [&](auto self, int u) -> void {
        num[u] = low[u] = ++timer;
        stack.push_back(u);
        for (int v : g[u]) {
            if (used[v]) continue;
            if (num[v]) {
                low[u] = min(low[u], num[v]);
            }
            else {
                self(self, v);
                low[u] = min(low[u], low[v]);
            }
        }
        if (num[u] == low[u]) {
            int v;
            do {
                v = stack.back();
                stack.pop_back();
                used[v] = true;
                scc_id[v] = scc;
            } while (v != u);
            ++scc;
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!num[i]) {
            dfs(dfs, i);
        }
    }
    if (scc == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<int>> h(scc);
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (scc_id[u] != scc_id[v]) {
                h[scc_id[u]].push_back(scc_id[v]);
            }
        }
    }
    vector<int> in(scc), out(scc);
    for (int u = 0; u < scc; ++u) {
        for (int v : h[u]) {
            in[v]++;
            out[u]++;
        }
    }
    int res = 0;
    int cur = 0;
    for (int i = 0; i < scc; ++i) {
        cur += in[i] == 0;
    }
    res = cur;
    cur = 0;
    for (int i = 0; i < scc; ++i) {
        cur += out[i] == 0;
    }
    res = max(res, cur);
    cout << res << '\n';
    return 0;
}
