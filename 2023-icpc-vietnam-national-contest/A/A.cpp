#include <bits/stdc++.h>
using namespace std;

#define hi cerr << "HiHiHi\n";

#ifndef LOCAL
#define cerr if (false) cerr
#endif

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e7 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c > 0) {
            cout << "CURVE UP" << '\n';
        }
        else if (c < 0) {
            cout << "CURVE DOWN" << '\n';
        }
        else {
            cout << "NO CURVE" << '\n';
        }
    }

    return 0;
}
