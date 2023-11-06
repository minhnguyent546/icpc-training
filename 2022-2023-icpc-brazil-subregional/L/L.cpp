#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = (int)1e5;
vector<vector<int>> adj;
vector<int> color, cnt, sz, big, cntTree, ans, par;
int n;

void dfsSz(int u, int p) {
    par[u] = p;
    sz[u] = 1;
    for(int v : adj[u]) {
        if(v != p) {
            dfsSz(v, u);
            sz[u] += sz[v];
        }
    }
}

void add(int u, int p, int del, int &res) {
    int c = color[u];
    res -= cnt[c] * (cntTree[c] - cnt[c]);
    cnt[c] += del;
    res += cnt[c] * (cntTree[c] - cnt[c]);
    for(int v : adj[u]) {
        if(v != p && big[v] == false) {
            add(v, u, del, res);
        }
    }
}

int dsuOnTree(int u, int p, int keep) {
    int b = -1, res = 0;
    for(int v : adj[u]) {
        if(v != p && (b == -1 || sz[b] < sz[v])) {
            b = v;
        }
    }
    for(int v : adj[u]) {
        if(v != p && v != b) {
            dsuOnTree(v, u, 0);
        }
    }
    if(b != -1) {
        big[b] = true;
        res = dsuOnTree(b, u, 1);
    }
    add(u, p, 1, res);
    ans[u] = res;
    if(b != -1) {
        big[b] = false;
    }
    if(keep == 0) {
        add(u, p, -1, res);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    adj.resize(n);
    color.resize(n);
    cntTree.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> color[i];
        color[i]--;
        cntTree[color[i]]++;
    }
    vector<pair<int,int>> queries;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        queries.push_back({u, v});
    }
    cnt.resize(n);
    sz.resize(n);
    big.resize(n);
    ans.resize(n);
    par.resize(n);
    dfsSz(0, -1);
    dsuOnTree(0, -1, 0);
    for(auto[u, v] : queries) {
        if(par[u] == v) {
            cout << ans[u] << ' ';
        } else {
            cout << ans[v] << ' ';
        }
    }
}
