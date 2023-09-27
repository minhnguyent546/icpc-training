/**            
 * author      minhnguyent546
 * created_at  Fri, 2023-09-22 23:31:57
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
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> wormholes(k);
    for (int i = 0; i < k; ++i) {
        cin >> wormholes[i];
        --wormholes[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s = 0, t = n - 1;
    auto bfs = [&](int source) -> vector<int> {
        vector<int> dist(n, INF);
        dist[source] = 0;
        vector<int> que = {source};
        for (int k = 0; k < (int) que.size(); ++k) {
            int u = que[k];
            for (int v : g[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    que.push_back(v);
                }
            }
        }
        return dist;
    };
    vector<int> dist_s = bfs(s), dist_t = bfs(t);
    long long sum = 0;
    for (int u : wormholes) sum += dist_t[u];

    int x = dist_s[t], y = 1;
    for (int u : wormholes) {
        long long cur_x = 1LL * dist_s[u] * (k - 1) + sum - dist_t[u];
        long long cur_y = k - 1;
        int d = __gcd(cur_x, cur_y);
        cur_x /= d;
        cur_y /= d;
        if (cur_x * y < x * cur_y) {
            x = cur_x;
            y = cur_y;
        }
    }
    cout << x << '/' << y << '\n';

    return 0;
}
