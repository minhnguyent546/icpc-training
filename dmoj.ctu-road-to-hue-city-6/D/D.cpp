/**            
 * author      minhnguyent546
 * created_at  Sun, 2023-10-01 00:24:40
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (119 << 23) + 1;
const int INF = 0x3f3f3f3f;
const int P = (int) 5e6;
int spf[P + 1];
vector<int> primes;

void sieve(int n = P) {
    for (int x = 2; x <= n; ++x) {
        if (spf[x] == 0) {
            primes.push_back(spf[x] = x);
        }
        for (int p : primes) {
            if (p > spf[x] || x * p > n) break;
            spf[x * p] = p;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    sieve();

    long long n;
    int k;
    cin >> n >> k;
    k = min(n - k, (long long) k);
    vector<long long> a(k);
    vector<int> b(k + 1);
    long long offset = n - k + 1;
    for (long long i = n - k + 1; i <= n; ++i) a[i - offset] = i;
    for (int i = 1; i <= k; ++i) b[i] = i;

    int res = 1;
    for (int &p : primes) {
        int pw = 0;
        for (long long i = (n - k + 1 + p - 1) / p * p; i <= n; i += p) {
            while (a[i - offset] % p == 0) {
                a[i - offset] /= p;
                ++pw;
            }
        }
        for (int i = p; i <= k; i += p) {
            while (b[i] % p == 0) {
                b[i] /= p;
                --pw;
            }
        }
        assert(pw >= 0);
        res = 1LL * res * (pw + 1) % MOD;
    }

    // remaining prime larger than sqrt(n)
    for (long long i = n - k + 1; i <= n; ++i) {
        if (a[i - offset] > 1) {
            res += res;
            if (res >= MOD) res -= MOD;
        }
    }
    cout << res << '\n';

    return 0;
}
