#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

const int LOG = 31;

struct Vertex
{
    int next[2];
    int cnt;
    Vertex()
    {
        fill(next, next + 2, -1);
        cnt = 0;
    }
};
struct Trie
{
    vector<Vertex> trie;
    Trie()
    {
        trie.emplace_back();
    }
    void insert(int val)
    {
        int i = 0;
        for (int j = LOG - 1; j >= 0; --j)
        {
            int bit = (val >> j) & 1;
            if (trie[i].next[bit] == -1)
            {
                trie[i].next[bit] = (int)trie.size();
                trie.emplace_back();
            }
            trie[i].cnt++;
            i = trie[i].next[bit];
        }
        trie[i].cnt++;
    }
    void remove(int val)
    {
        int i = 0;
        trie[i].cnt--;
        for (int j = LOG - 1; j >= 0; --j)
        {
            int bit = (val >> j) & 1;
            int ni = trie[i].next[bit];
            if (ni == -1 || trie[ni].cnt == 1)
            {
                trie[i].next[bit] = -1;
                return;
            }
            i = ni;
            trie[i].cnt--;
        }
    }
    int get_max(int x)
    {
        int i = 0;
        int res = 0;
        for (int j = LOG - 1; j >= 0; --j)
        {
            int bit = (x >> j) & 1;
            if (trie[i].next[!bit] != -1)
            {
                res += (1 << j);
                i = trie[i].next[!bit];
            }
            else
            {
                i = trie[i].next[bit];
            }
        }
        return res;
    }
    int get_min(int x)
    {
        int i = 0;
        int res = 0;
        for (int j = LOG - 1; j >= 0; --j)
        {
            int bit = (x >> j) & 1;
            if (trie[i].next[bit] != -1)
            {
                i = trie[i].next[bit];
            }
            else
            {
                res += (1 << j);
                i = trie[i].next[!bit];
            }
        }
        return res;
    }
};

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    if (n == 2)
    {
        cout << g[0][0].second << ' ' << g[0][0].second << '\n';
        return 0;
    }
    vector<int> x(n);
    int root = 0;
    auto dfs = [&](auto self, int u, int prev = -1) -> void
    {
        for (auto [v, w] : g[u])
        {
            if (v == prev)
                continue;
            x[v] = x[u] ^ w;
            self(self, v, u);
        }
    };
    dfs(dfs, root);
    for (int u = 0; u < n; ++u)
    {
    }
    Trie trie;
    for (int u = 0; u < n; ++u)
    {
        trie.insert(x[u]);
    }
    int res_minv = INT_MAX, res_maxv = INT_MIN;
    for (int u = 0; u < n; ++u)
    {
        trie.remove(x[u]);
        int minv = trie.get_min(x[u]);
        int maxv = trie.get_max(x[u]);
        res_minv = min(res_minv, minv);
        res_maxv = max(res_maxv, maxv);
        trie.insert(x[u]);
    }
    cout << res_minv << ' ' << res_maxv << '\n';

    return 0;
}
