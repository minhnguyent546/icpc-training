#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = (int) s.size();
    assert(n >= 2);
    int k;
    cin >> k;
    string best = "";
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n - 1; ++i) {
            string cur = s.substr(i, 2);
            if (best == "" || best > cur) {
                best = cur;
            }
        }
        reverse(s.begin(), s.end());
    }
    string ans = "";
    for (int i = 0; i < (k + 1) / 2; ++i) {
        ans += best;
    }
    if (k & 1) ans.pop_back();
    cout << ans << '\n';
    return 0;
}
