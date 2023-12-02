#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

const int P = (int) 1e5;
vector<int> primes;
int spf[P + 1];
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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    sieve();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map<int, int> freq;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int v = arr[i];
        int cur = 1;
        for (int p : primes) {
            if (p * p > v) break;
            if (v % p == 0) {
                cur *= p;
                while (v % p == 0) v /= p;
            }
        }
        if (v > 1) cur *= v;
        res += freq[cur]++;
    }
    cout << res << '\n';
    return 0;
}