/**            
 * author      minhnguyent546
 * created_at  Tuesday, 2023-09-12 22:36:33
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

const int N = 9999;
int dist[N + 1];

void precompute() {
    int s = 0;
    for (int i = 0; i <= N; ++i) dist[i] = INF;
    vector<string> que;
    que.emplace_back("0000");
    dist[s] = 0;
    for (int k = 0; k < (int) que.size(); ++k) {
        auto u = que[k];
        int num_u = stoi(u);
        for (int t = 1; t <= 4; ++t) {
            for (int i = 0; i <= 4 - t; ++i) {
                string v = u, w = u;
                for (int j = i; j < i + t; ++j) {
                    v[j] = (v[j] == '9' ? '0' : v[j] + 1);
                    w[j] = (w[j] == '0' ? '9' : w[j] - 1); 
                    int num_v = stoi(v);
                    int num_w = stoi(w);
                    if (dist[num_v] == INF) {
                        dist[num_v] = dist[num_u] + 1;
                        que.emplace_back(v);
                    }
                    if (dist[num_w] == INF) {
                        dist[num_w] = dist[num_u] + 1;
                        que.emplace_back(w);
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    precompute();
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        int diff = 0;
        for (int i = 3; i >= 0; --i) {
            diff = diff * 10 + ((t[i] - s[i] + 10) % 10);
        }
        cout << dist[diff] << '\n';
    }

    return 0;
}
