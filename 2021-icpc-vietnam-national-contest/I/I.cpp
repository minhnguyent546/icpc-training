#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

#define int long long

const int N = 50 + 3;
const int R = 15;
long long dp[R + 3][R + 3][R + 3][R + 3][R + 3];
long long next_dp[R + 3][R + 3][R + 3][R + 3][R + 3];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<string> names = {"dp", "graph", "mathgeo", "ds", "adhoc"};
    auto idx = [&](string s) -> int {
        for (int i = 0; i < (int) names.size(); ++i) {
            if (names[i] == s) return i;
        }
        assert(false);
        return -1;
    };    
    int n;
    cin >> n;
    const int m = 5;
    vector<vector<int>> tags(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            string bar;
            cin >> bar;
            tags[i][idx(bar)]++;
        }
    }
    bool all_zero = true;
    vector<array<int, 2>> range(m);
    for (int i = 0; i < m; ++i) {
        cin >> range[i][0] >> range[i][1];
        if (range[i][0] > 0) all_zero = false;
    }
    dp[0][0][0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int a = 0; a <= R; ++a) {
            for (int b = 0; b <= R; ++b) {
                for (int c = 0; c <= R; ++c) {
                    for (int d = 0; d <= R; ++d) {
                        for (int e = 0; e <= R; ++e) {
                            int na = a - tags[i - 1][0];
                            int nb = b - tags[i - 1][1];
                            int nc = c - tags[i - 1][2];
                            int nd = d - tags[i - 1][3];
                            int ne = e - tags[i - 1][4];
                            next_dp[a][b][c][d][e] = dp[a][b][c][d][e];
                            if (min({na, nb, nc, nd, ne}) < 0) continue;
                            next_dp[a][b][c][d][e] += dp[na][nb][nc][nd][ne];
                        }
                    }
                }
            }
        }
        for (int a = 0; a <= R; ++a) {
            for (int b = 0; b <= R; ++b) {
                for (int c = 0; c <= R; ++c) {
                    for (int d = 0; d <= R; ++d) {
                        for (int e = 0; e <= R; ++e) {
                            dp[a][b][c][d][e] = next_dp[a][b][c][d][e];
                            next_dp[a][b][c][d][e] = 0;
                        }
                    }
                }
            }
        }
    }
    long long res = 0;
    for (int a = range[0][0]; a <= range[0][1]; ++a) {
        for (int b = range[1][0]; b <= range[1][1]; ++b) {
            for (int c = range[2][0]; c <= range[2][1]; ++c) {
                for (int d = range[3][0]; d <= range[3][1]; ++d) {
                    for (int e = range[4][0]; e <= range[4][1]; ++e) {
                        res += dp[a][b][c][d][e];
                    }
                }
            }
        }
    }
    cout << res - all_zero << '\n';
    return 0;
}
