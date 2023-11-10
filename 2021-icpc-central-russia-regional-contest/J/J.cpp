#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

using num_t = long long;
const int PRIME_MAX = (int) 4e4;
const int LIMIT = (int) 1e9;
vector<int> primes;
int spf[PRIME_MAX + 3];
int small_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 73, 113, 193, 311, 313, 407521, 299210837};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void sieve(int n = PRIME_MAX) {
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

num_t mulmod(num_t a, num_t b, num_t mod) {
    num_t res = 0;
    while (b > 0) {
        if (b & 1) res = (1LL * res + a) % mod;
        a = (1LL * a + a) % mod;
        b >>= 1;
    }
    return res;
}

num_t powmod(num_t a, num_t n, num_t mod) {
    num_t res = 1;
    a %= mod;
    while (n > 0) {
        if (n & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        n >>= 1;
    }
    return res;
}

bool miller_rabin(num_t a, num_t d, int s, num_t mod) {
    num_t x = powmod(a, d, mod);
    if (x == mod - 1 || x == 1) {
        return true;
    }
    for (int i = 0; i < s - 1; ++i) {
        x = mulmod(x, x, mod);
        if (x == mod - 1) return true;
    }
    return false;
}

bool is_prime(num_t n, int test = 10) {
    if (n < 4) return (n > 1);
    num_t d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d >>= 1;
        ++s;
    }
    for (int i = 0; i < test; ++i) {
        int a = small_primes[i];
        if (n == a) return true;
        if (n % a == 0 || !miller_rabin(a, d, s, n)) return false;
    }
    return true;
}

num_t f(num_t x, int c, num_t mod) {
    x = mulmod(x, x, mod);
    x += c;
    if (x >= mod) x -= mod;
    return x;
}

num_t pollard_rho(num_t n, int c) {
    num_t x = 2, y = x, d;
    long long p = 1;
    num_t dist = 0;
    while (true) {
        y = f(y, c, n);
        dist++;
        d = __gcd(abs(x - y), n);
        if (d > 1) break;
        if (dist == p) {
            dist = 0;
            p *= 2;
            x = y;
        }
    }
    return d;
}

void factorize(num_t n, vector<num_t> &factors) {
    int _ = (int) sqrt(n);
    for (int p : primes) {
        if (p > _) break;
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }
    if (n > 1) factors.push_back(n);
}

void llfactorize(num_t n, vector<num_t> &factors) {
    if (n < 2) return;
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    if (n < LIMIT) {
        factorize(n, factors);
        return;
    }
    num_t d = n;
    for (int c = 2; d == n; ++c) {
        d = pollard_rho(n, c);
    }
    llfactorize(d, factors);
    llfactorize(n / d, factors);
}

void solve(long long n) {
    vector<num_t> factors;
    llfactorize(n, factors);
    sort(factors.begin(), factors.end());
    set<num_t> s;
    for (num_t p : factors) {
        if (s.count(p)) {
            cout << -1 << '\n';
            return;
        }
        s.insert(p);
    }
    if ((int) s.size() != 6) {
        cout << -1 << '\n';
        return;
    }
    for (num_t p : s) {
        cout << p << ' ';
    }
    cout << '\n';
}

long long next(long long a, long long b) {
    return uniform_int_distribution<long long>(a, b)(rng);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    sieve();
    long long n;
    cin >> n;
    solve(n);

    return 0;
}
