#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    string t = "edgnb";
    int n = (int) s.size(), m = (int) t.size();
    int cnt = 0;
    for (int i = 0; i <= n - m; ++i) {
        if (s.substr(i, m) == t) {
            ++cnt;
        }
    }
    cout << cnt << '\n';

    return 0;
}
