#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

vector<int> myFact, yourFact;
vector<vector<int>> adj;
vector<bool> used;
vector<int> st;

void dfs(int u) {
    st.push_back(u);
    used[u] = true;
    for(int v : adj[u]) {
        if(used[v] == false) {
            dfs(v);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    myFact.resize(n);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        myFact[x]++;
    }
    int k;
    cin >> k;
    vector<int> ks(k);
    for(int &x : ks) {
        cin >> x;
    }
    int l;
    cin >> l;
    yourFact.resize(n);
    for(int i = 0; i < l; i++) {
        int x;
        cin >> x;
        x--;
        yourFact[x]++;
    }
    int g;
    cin >> g;
    adj.resize(n);
    used.resize(n);
    for(int i = 0; i < g; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cntYour = 0;
    for(int i = 0; i < n; i++) {
        if(used[i] == false) {
            dfs(i);
            int my = 0, your = 0;
            for(int x : st) {
                my += myFact[x];
                your += yourFact[x];
            }
            cntYour += min(my, your);
            st.clear();
        }
    }
    if(k >= m) {
        cout << m << ' ' << 0 << '\n';
    } else if(cntYour + k >= m) {
        int r = cntYour + k - m;
        cout << k << ' ' << cntYour - r << '\n';
    } else {
        cout << k << ' ' << cntYour << '\n';
    }
    return 0;
}
