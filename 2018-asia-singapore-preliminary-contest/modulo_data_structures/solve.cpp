/**            
 * author      minhnguyent546
 * created_at  Sat, 2023-10-14 15:38:33
 * problem     https://open.kattis.com/problems/modulodatastructures
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

const int SZ = 500;
const int N = (int) 2e5;
int inc[SZ][SZ];
int arr[N + 1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int k = 0; k < q; ++k) {
        int type;
        cin >> type;
        if (type == 1) {
            int A, B, C;
            cin >> A >> B >> C;
            if (B < SZ) {
                inc[B][A] += C;
            } else {
                for (int i = A; i <= n; i += B) {
                    arr[i] += C;
                }
            }
        } else {
            int D;
            cin >> D;
            int res = arr[D];
            for (int B = 1; B < SZ; ++B) {
                res += inc[B][D % B];
            }
            cout << res << '\n';
        }
    }
    // Time complexity: O(Q * SZ)
    return 0;
}
