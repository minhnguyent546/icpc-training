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

const long long N = (long long) 1e18;
vector<long long> fib;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    fib = {1, 1};
    int sz = (int) fib.size();
    while (fib.back() < N) {
        fib.push_back(fib[sz - 1] + fib[sz - 2]);
        ++sz;
    }
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<map<long long, int>> f(sz);
        auto dfs = [&](auto self, int pos, long long n) -> int {
            if (n == 1) return 1;
            if (pos == sz) return 0;
            if (f[pos].count(n)) return f[pos][n];
            int res = 0;
            for (int i = pos; i < sz; ++i) {
                long long cur = n;
                while (cur % fib[i] == 0) {
                    cur /= fib[i];
                    res += self(self, i + 1, cur);
                }
            }
            return f[pos][n] = res;
        };
        int res = dfs(dfs, 2, n);
        cout << res << '\n';
    }

    return 0;
}
