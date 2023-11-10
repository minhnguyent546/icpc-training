#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int calc(int x1, int y1, int x2, int y2) {
    int x = (x1 + y1 + x2 - y2);
    int y = (x1 + y1 + y2 - x2);
    if (x & 1 || y & 1) return 1e18;
    x = x / 2;
    y = y / 2;
    return 2 * abs(x1 - x) + 2 * abs(x2 - x);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << min({calc(x1, y1, x2, y2),
                    calc(x1, y1, x2 + 1, y2) + 1,
                    calc(x1, y1, x2 - 1, y2) + 1,
                    calc(x1, y1, x2, y2 + 1) + 1,
                    calc(x1, y1, x2, y2 - 1) + 1}) << '\n';
    }

    return 0;
}
