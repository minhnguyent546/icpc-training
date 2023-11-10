#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int k = 4;
    vector<int> cnt(n);
    vector<vector<array<int, 2>>> edges(k);
    for (int w = 0; w < k; ++w) {
        int m, g;
        cin >> m >> g;
        for (int i = 0; i < m; ++i) {
            int u;
            cin >> u;
            --u;
            cnt[u]++;
        }
        for (int i = 0; i < g; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            edges[w].push_back({u, v});
        }
    }
    for (int w = 0; w < k; ++w) {
        long long res = 0;
        for (auto [u, v] : edges[w]) {
            res += cnt[u];
            if (v != u) res += cnt[v];
        }
        cout << res << ' ';
    }
    cout << '\n';


    return 0;
}
