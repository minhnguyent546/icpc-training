#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x, y;
    cin >> n >> x >> y;
    int m = (1 << n);
    auto in_grid = [&](int x, int y) -> bool {
        return (0 <= min(x, y) && max(x, y) <= m);
    };
    vector<pair<int, int>> que;
    que.emplace_back(x, y);
    vector<map<int, int>> dist(m + 1);
    vector<set<int>> vis(m + 1);
    vis[0].insert(0);
    dist[0][0] = 0;
    for (int k = 0; k < (int) que.size(); ++k) {
        auto [r, c] = que[k];
        if (r == m / 2 && c == m / 2) {
            cout << dist[r][c] << '\n';
            return 0;
        }
        for (int dr : {0, m}) {
            for (int dc : {0, m}) {
                int nr = 2 * r - dr;
                int nc = 2 * c - dc;
                if (in_grid(nr, nc) && !vis[nr].count(nc)) {
                    dist[nr][nc] = dist[r][c] + 1;
                    vis[nr].insert(nc);
                    que.emplace_back(nr, nc);
                    if (nr ==  m / 2 && nc == m / 2) {
                        cout << dist[nr][nc] << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    assert(false);
    return 0;
}
