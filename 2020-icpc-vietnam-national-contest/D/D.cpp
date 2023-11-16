/**            
 * author      minhnguyent546
 * created_at  Fri, 2023-11-10 16:32:30
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
// const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 1; i < n; ++i) {
            int par, w;
            cin >> par >> w;
            --par;
            g[par].emplace_back(i, w);
            g[i].emplace_back(par, w);
        }
        vector<long long> down(n);
        vector<long long> diam(n);
        auto dfs = [&](auto self, int u, int par = -1) -> void {
            long long max_down = 0, second_max_down = 0;
            for (auto [v, w] : g[u]) {
                if (v == par) continue;
                self(self, v, u);
                diam[u] = max(diam[u], diam[v]);
                if (down[v] + w > max_down) {
                    second_max_down = max_down;
                    max_down = down[v] + w;
                }
                else {
                    second_max_down = max(second_max_down, down[v] + w);
                }
            }
            down[u] = max_down;
            diam[u] = max(diam[u], max_down + second_max_down);
        };
        int root = 0;
        dfs(dfs, root);
        vector<long long> up(n), up_diam(n);
        auto dfs1 = [&](auto self, int u, int par = -1) -> void {
            multiset<long long, greater<>> st;
            st.insert(up[u]);
            for (auto [v, w] : g[u]) {
                if (v == par) continue;
                st.insert(down[v] + w);
            }
            for (auto [v, w] : g[u]) {
                if (v == par) continue;
                auto it = st.find(down[v] + w);
                assert(it != st.end());
                st.erase(it);
                auto it_max = st.begin();
                up[v] = (it_max != st.end() ? *it_max : 0) + w;
                up_diam[v] = (it_max != st.end() ? *it_max : 0);
                if (it_max != st.end() && next(it_max) != st.end()) {
                    up_diam[v] += *next(it_max);
                }
                up_diam[v] = max(up_diam[v], up_diam[u]);
                st.insert(down[v] + w);
            }
            multiset<long long, greater<>> h;
            for (auto [v, w] : g[u]) {
                if (v == par) continue;
                h.insert(diam[v]);
            }
            for (auto [v, w] : g[u]) {
                if (v == par) continue;
                auto it = h.find(diam[v]);
                assert(it != h.end());
                h.erase(it);
                if (!h.empty()) {
                    up_diam[v] = max(up_diam[v], *h.begin());
                }
                h.insert(diam[v]);
            }
            for (auto [v, w] : g[u]) {
                if (v != par) self(self, v, u);
            }
        };
        dfs1(dfs1, root);
        long long ans = INF_LL;
        for (int i = 0; i < n; ++i) {
            if (i == root) continue;
            ans = min(ans, abs(diam[i] - up_diam[i]));
        }
        cout << ans << '\n';
    }

    return 0;
}
