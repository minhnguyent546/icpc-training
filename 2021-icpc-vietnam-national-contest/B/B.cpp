#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int r = 0; r < n; ++r) {
        cin >> arr[r];
    }
    const char minchar = 'A';
    const char maxchar = 'Z';
    const int ALPHABET = 26;
    auto trans = [&](char a, char b) {
        if (a > b) swap(a, b);
        return min(b - a, a - minchar + maxchar - b + 1);
    };
    int res = 0;
    for (int r = 0; r <= (n - 1) / 2; ++r) {
        for (int c = 0; c <= (m - 1) / 2; ++c) {
            set<pair<int, int>> s;
            s.emplace(r, c);
            s.emplace(r, m - c - 1);
            s.emplace(n - r - 1, c);
            s.emplace(n - r - 1, m - c - 1);
            int best_cur = INF;
            for (char ch = minchar; ch <= maxchar; ++ch) {
                int cur = 0;
                for (auto [r, c] : s) {
                    cur += trans(arr[r][c], ch);
                }
                best_cur = min(best_cur, cur);
            }
            res += best_cur;
        }
    }
    cout << res << '\n';
    return 0;
}