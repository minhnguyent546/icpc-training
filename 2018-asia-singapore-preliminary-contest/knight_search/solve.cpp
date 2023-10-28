#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> grid(n);
    string foo;
    cin >> foo;
    for (int i = 0; i < n * n; i += n) {
        grid[i / n] = foo.substr(i, n);
    }
    string want = "ICPCASIASG";
    auto valid = [&](int r, int c) {
        return (0 <= min(r, c) && max(r, c) < n);
    };
    auto find = [&](auto self, int i, int r, int c) -> bool {
        // cerr << i << ' ' << r << ' ' << c << ' ' << grid[r][c] << '\n';
        if (i == (int) want.size()) {
            return true;
        }
        for (int dr = -2; dr <= 2; ++dr) {
            for (int dc = -2; dc <= 2; ++dc) {
                if (dr * dr + dc * dc != 5) continue;
                int nr = r + dr;
                int nc = c + dc;
                if (valid(nr, nc) && grid[nr][nc] == want[i]) {
                    if (self(self, i + 1, nr, nc)) {
                        return true;
                    }
                }
            }
        }
        return false;
    };
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == want[0]) {
                if (find(find, 1, r, c)) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
    return 0;
}
