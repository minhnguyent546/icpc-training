#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n);
    vector<int> comp(n);
    auto dfs = [&](auto self, int u, int id) -> void {
        vis[u] = true;
        comp[u] = id;
        for (int v : g[u]) {
            if (!vis[v]) self(self, v, id);
        }
    };
    for (int i = 0, cnt = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(dfs, i, cnt++);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (comp[i] != comp[n - i - 1])  {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
