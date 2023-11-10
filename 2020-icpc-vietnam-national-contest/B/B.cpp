#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                cin >> grid[r][c];
            }
        }
        vector<vector<bool>> immune(n, vector<bool>(m));
        vector<vector<bool>> has(n, vector<bool>(m));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == '.') continue;
                if (grid[r][c] == '#') has[r][c] = true;
                else immune[r][c] = true;
            }
        }
        auto valid = [&](int r, int c) -> bool {
            return (0 <= r && r < n && 0 <= c && c < m);
        };
        deque<pair<int, int>> dq;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        for (int c = 0; c < m; ++c) {
            if (immune[0][c]) continue;
            int w = !has[0][c];
            dist[0][c] = w;
            if (w == 0) dq.emplace_front(0, c);
            else dq.emplace_back(0, c);
        }
        for (int r = 0; r < n; ++r) {
            if (immune[r][m - 1]) continue;
            int w = !has[r][m - 1];
            dist[r][m - 1] = w;
            if (w == 0) dq.emplace_front(r, m - 1);
            else dq.emplace_back(r, m - 1);
        }
        while (!dq.empty()) {
            auto [r, c] = dq.front(); dq.pop_front();
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr;
                    int nc = c + dc;
                    if (valid(nr, nc) && !immune[nr][nc]) {
                        int w = !has[nr][nc];
                        if (dist[nr][nc] > w + dist[r][c]) {
                            dist[nr][nc] = w + dist[r][c];
                            if (w == 0) dq.emplace_front(nr, nc);
                            else dq.emplace_back(nr, nc);
                        }
                    }
                }
            }
        }
        int res = INF;
        for (int r = 0; r < n; ++r) {
            res = min(res, dist[r][0]);
        }
        for (int c = 0; c < m; ++c) {
            res = min(res, dist[n - 1][c]);
        }
        cout << (res < INF ? res : -1) << '\n';
    }
    return 0;
}
