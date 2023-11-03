#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
using Mat = vector<vector<int>>;

Mat mult(Mat a, Mat b) {
    int n = (int) a.size();
    Mat ans(n, vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            for (int g = 0; g < n; ++g) {
                ans[r][c] = (ans[r][c] + 1LL * a[r][g] * b[g][c]) % MOD;
            }
        }
    }
    return ans;
}

Mat powmod(Mat a, long long k) {
    int n = (int) a.size();
    Mat res(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) res = mult(res, a);
        a = mult(a, a);
        k >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int sz = n * m;
    vector<vector<int>> adj(sz, vector<int>(sz));
    string dirs = "LRUD";
    int drow[] = {0, 0, -1, 1};
    int dcol[] = {-1, 1, 0, 0};
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    auto valid = [&](int r, int c) {
        return (0 <= r && r < n && 0 <= c && c < m && grid[r][c] != '#');
    };
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '#') continue;
            vector<int> ts;
            if (grid[r][c] == '+') ts = {0, 1, 2, 3};
            else ts.push_back((int) dirs.find(grid[r][c]));

            for (int t : ts) {
                int nr = r + drow[t];
                int nc = c + dcol[t];
                if (valid(nr, nc)) {
                    adj[r * m + c][nr * m + nc] = 1;
                }
            }
        }
    }
    Mat T = powmod(adj, k);
    int res = 0;
    for (int u = 0; u < sz; ++u) {
        for (int v = 0; v < sz; ++v) {
            res += T[u][v];
            if (res >= MOD) res -= MOD;
        }
    }
    cout << res << '\n';
    // T[u][v] = the number of paths of length k from u to v.
    return 0;
}
