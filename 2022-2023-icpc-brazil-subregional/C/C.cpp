#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if (false) cerr
#endif

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int V = (int) 1e3;
int valX[V + 3][V + 3], valY[V + 3][V + 3];
bool vis[V + 3][V + 3];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<array<int, 2>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    arr.push_back(arr.front());
    ++n;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i][0] == arr[i + 1][0]) {
            int x = arr[i][0];
            auto [l, r] = minmax(arr[i][1], arr[i + 1][1]);
            valX[x][l]++;
            valX[x][r]--;
        }
        else if (arr[i][1] == arr[i + 1][1]) {
            int y = arr[i][1];
            auto [l, r] = minmax(arr[i][0], arr[i + 1][0]);
            valY[y][l]++;
            valY[y][r]--;
        }
        else assert(false);
    }
    for (int i = 0; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            valX[i][j] += valX[i][j - 1];
            valY[i][j] += valY[i][j - 1];
        }
    }
    auto valid = [&](int x, int y) {
        return (0 <= min(x, y) && max(x, y) <= V && !vis[x][y]);
    };
    auto bfs = [&](int start_x, int start_y) -> int {
        vector<array<int, 2>> que;
        que.push_back({start_x, start_y});
        vis[start_x][start_y] = true;
        int comp = 0;
        for (int k = 0; k < (int) que.size(); ++k) {
            auto [x, y] = que[k];
            comp++;
            // left
            if (valid(x - 1, y) && valX[x][y] == 0) {
                vis[x - 1][y] = true;
                que.push_back({x - 1, y});
            }
            // right
            if (valid(x + 1, y) && valX[x + 1][y] == 0) {
                vis[x + 1][y] = true;
                que.push_back({x + 1, y});
            }
            // up
            if (valid(x, y + 1) && valY[y + 1][x] == 0) {
                vis[x][y + 1] = true;
                que.push_back({x, y + 1});
            }
            // down
            if (valid(x, y - 1) && valY[y][x] == 0) {
                vis[x][y - 1] = true;
                que.push_back({x, y - 1});
            }
        }
        return comp;
    };
    bfs(0, 0);
    int res = -INF;
    for (int x = 0; x <= V; ++x) {
        for (int y = 0; y <= V; ++y) {
            if (!vis[x][y]) {
                int cur = bfs(x, y);
                res = max(res, cur);
            }
        }
    }
    cout << res << '\n';
    return 0;
}
