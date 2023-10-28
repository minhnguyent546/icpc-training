#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e6 + 3;
int phi[N];
int spf[N];
bool seen[N + 3];
int inv[N + 3];
int fact[N + 3], inv_fact[N + 3];
vector<int> primes;
void sieve(int n = N) {
	phi[1] = 1;
	for (int x = 2; x <= n; ++x) {
		if (spf[x] == 0) {
			primes.push_back(spf[x] = x);
			phi[x] = x - 1;
		}
		for (int p : primes) {
			if (p > spf[x] || x * p > n) break;
			spf[x * p] = p;
			if (p == spf[x]) {
				phi[x * p] = phi[x] * p;
			}
			else {
				phi[x * p] = phi[x] * phi[p];
			}
		}
	}
}

const int MOD = 998244353;

int powmod(long long a, long long n, int mod = MOD) {
	int res = 1;
	a %= mod;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
void precompute(int n = N) {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = 1LL * fact[i - 1] * i % MOD;
	}
	inv_fact[n] = powmod(fact[n], MOD - 2);
	for (int i = n; i > 0; --i) {
		inv_fact[i - 1] = 1LL * i * inv_fact[i] % MOD;
	}
	for (int i = 1; i <= n; ++i) {
		inv[i] = 1LL * fact[i - 1] * inv_fact[i] % MOD;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	sieve();
	precompute();
	int a, b;
	cin >> a >> b;
	int ans = phi[a];
	int cur = a;
	while (cur > 1) {
		int p = spf[cur];
		while (cur % p == 0) {
			cur /= p;
		}
		seen[p] = true;
	}
	for (int i = 2; i <= b; ++i) {
		int cur_res = phi[a];
		int cur = i;
		cur_res = 1LL * cur_res * i % MOD;
		while (cur > 1) {
			int p = spf[cur];
			while (cur % p == 0) {
				cur /= p;
			}
			if (!seen[p]) {
				cur_res = (cur_res - 1LL * cur_res * inv[p]) % MOD;
				if (cur_res < 0) cur_res += MOD;
			}
		}
		ans = (1LL * ans + cur_res) % MOD;
	}
	cout << ans << '\n';
	return 0;
}
