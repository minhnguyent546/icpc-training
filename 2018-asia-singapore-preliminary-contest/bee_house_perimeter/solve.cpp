#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

#define cerr if (false) cerr

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int R, K;
    cin >> R >> K;
    int n = 3 * R * (R - 1) + 1;
    vector<bool> chosen(n);
    for (int i = 0; i < K; ++i) {
        int val;
        cin >> val;
        --val;
        chosen[val] = true;
    }
    vector<vector<int>> g(n);
    vector<vector<int>> vals(R * 2 - 1);
    int cnt = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < R + i; ++j) {
            vals[i].push_back(cnt++);
        }
    }
    for (int i = R; i < R * 2 - 1; ++i) {
        for (int j = 0; j < 3 * R - i - 2; ++j) {
            vals[i].push_back(cnt++);
        }
    }

    // construct graph
    auto add_edge = [&](int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    };
    for (int i = 0; i < 2 * R - 1; ++i) {
        for (int j = 0; j < (int) vals[i].size() - 1; ++j) {
            add_edge(vals[i][j], vals[i][j + 1]);
        }
    }
    for (int i = 0; i < R - 1; ++i) {
        for (int j = 0; j < (int) vals[i].size(); ++j) {
            add_edge(vals[i][j], vals[i + 1][j]);
            add_edge(vals[i][j], vals[i + 1][j + 1]);
        }
    }
    for (int i = R; i < 2 * R - 1; ++i) {
        for (int j = 0; j < (int) vals[i].size(); ++j) {
            add_edge(vals[i][j], vals[i - 1][j]);
            add_edge(vals[i][j], vals[i - 1][j + 1]);
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (chosen[i]) {
            int side = 6;
            for (int v : g[i]) {
                if (chosen[v]) --side;
            }
            res += side;
        }
    }
    queue<int> q;
    vector<bool> vis(n);
    vector<int> bounds;
    for (int v : vals[0]) {
        if (!chosen[v]) {
            q.push(v);
            bounds.push_back(v);
            vis[v] = true;
        }
    }
    for (int v : vals.back()) {
        if (!chosen[v]) {
            q.push(v);
            bounds.push_back(v);
            vis[v] = true;
        }
    }
    for (int i = 1; i < (int) vals.size() - 1; ++i) {
        for (int v : {vals[i].front(), vals[i].back()}) {
            if (!chosen[v]) {
                q.push(v);
                bounds.push_back(v);
                vis[v] = true;
            }
        }
    }
    // cerr << "bound: " << '\n';
    // for (int v : bounds) {
    //  cerr << v << ' ';
    // }
    // cerr << '\n';
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cerr << "visit from bound: " << u << '\n';
        for (int v : g[u]) {
            if (!chosen[v] && !vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    auto bfs = [&](int u) {
        vis[u] = true;
        queue<int> q;
        q.push(u);
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (chosen[v]) {
                    ++cnt;
                    continue;
                }
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return cnt;
    };
    for (int i = 0; i < n; ++i) {
        cerr << i << ' ' << vis[i] << '\n';
        if (!vis[i] && !chosen[i]) {
            cerr << "remain: " << i << '\n';
            res -= bfs(i);
        }
    }
    cout << res << '\n';

    return 0;
}
