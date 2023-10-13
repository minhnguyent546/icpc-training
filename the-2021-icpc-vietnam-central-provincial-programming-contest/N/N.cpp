#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    const char minchar = 'a';
    const int ALPHABET = 26;
    const int INF = 0x3f3f3f3f;
    string s, t;
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size();
    vector<vector<int>> first(n + 1, vector<int>(ALPHABET));
    for (int i = 0; i < ALPHABET; ++i) first[n][i] = INF;
    for (int i = n - 1; i >= 0; --i) {
        for (int ch = 0; ch < ALPHABET; ++ch) {
            char cur_ch = s[i] - minchar;
            first[i][ch] = (ch == cur_ch ? i : first[i + 1][ch]);
        }
    }
    vector<int> ft(ALPHABET);
    for (char ch : t) ft[ch - minchar]++;

    vector<vector<int>> freq(n + 1, vector<int>(ALPHABET));
    for (int i = n - 1; i >= 0; --i) {
        freq[i] = freq[i + 1];
        int ch = s[i] - minchar;
        freq[i][ch]++;
    }
    auto gte = [&](auto &lhs, auto &rhs) {
        for (int i = 0; i < ALPHABET; ++i) {
            if (lhs[i] < rhs[i]) return false;
        }
        return true;
    };
    if (!gte(freq[0], ft)) {
        cout << -1 << '\n';
        return 0;
    }
    string ans = "";
    for (int i = 0, j = 0; i < m; ++i) {
        bool found = false;
        for (int choose = 0; choose < ALPHABET; ++choose) {
            if (ft[choose] == 0) continue;
            int k = first[j][choose];
            if (k == INF) continue;
            --ft[choose];
            if (gte(freq[k + 1], ft)) {
                found = true;
                ans += (char) (choose + minchar);
                j = k + 1;
                found = true;
                break;
            }
            ++ft[choose];
        }
        assert(found);
    }
    cout << ans << '\n';
    return 0;
}
