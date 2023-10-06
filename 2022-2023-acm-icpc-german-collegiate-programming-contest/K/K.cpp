/**            
 * author      minhnguyent546
 * created_at  Thu, 2023-10-05 14:35:04
 **/           
#include <bits/stdc++.h>
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
    int n, k; cin >> n >> k;
    int last = 0, pos = 0;
    string s; cin >> s;
    last = 1;
    while (pos < n && k != 0) {
        int next = !last;
        if (next == 1) {
            if (s[pos] == 'L') {
                k--;
                last = !last;
            } else {
                pos++;
                last = next;
            }
        } else {
            if (s[pos] == 'R') {
                k--;
                last = !last;
            } else {
                pos++;
                last = next;
            }
        }
    }

    cout << k << '\n';

    return 0;
}
