/**            
 * author      minhnguyent546
 * created_at  Fri, 2023-09-22 21:49:42
 **/           
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int res = 0;
    res += (n >= 10 ? (int) log10(n) : 1); // for digit 0
    for (int d = 1; d < 10; ++d) {
        long long cur = d;
        while (cur <= n) {
            ++res;
            cur = cur * 10 + d;
        }
    }
    cout << res << '\n';

    return 0;
}
