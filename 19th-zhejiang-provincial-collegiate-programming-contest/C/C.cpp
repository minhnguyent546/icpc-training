/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), b(m);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= x) ++res;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] <= x) ++res;
    }
    cout << res << '\n';

    return 0;
}
