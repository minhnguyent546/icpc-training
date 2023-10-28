#include <bits/stdc++.h>

using namespace std;
vector<int> masks;
void gen(int n, int i, int cur) {
	if (i >= n) {
		masks.push_back(cur);
		return;
	}
	gen(n, i + 1, cur);
	gen(n, i + 2, cur + (1 << i));
}

bool compatible(int a, int b) {
	if (a & b) return false;
	if (a & (b >> 1)) return false;
	if (a & (b << 1)) return false;
	return true;
}

const int MOD = 123456789;
#ifndef LOCAL
#define cerr if (false) cerr
#endif
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, K;
	cin >> n >> m >> K;
	if (n > m) swap(n, m);
	assert(n <= 16);
	gen(n, 0, 0);
	int maxv = *max_element(masks.begin(), masks.end());
	vector<vector<int>> compatibles(maxv + 1);
	for (int mask : masks) {
		for (int other : masks) {
			if (compatible(mask, other)) {
				compatibles[mask].push_back(other);
			}
		}
	}
	vector<vector<int>> dp(K + 1, vector<int>(maxv + 1));
	for (int mask : masks) {
		int ones = __builtin_popcount(mask);
		if (ones > K) continue;
		dp[ones][mask] = 1;
	}
	for (int i = 0; i < m - 1; ++i) {
		vector<vector<int>> new_dp(K + 1, vector<int>(maxv + 1));
		for (int k = 0; k <= K; ++k) {
			for (int mask : masks) {
				if (dp[k][mask] == 0) continue;
				for (int other : compatibles[mask]) {	
					int ones = __builtin_popcount(other);
					if (k + ones > K) continue;
					new_dp[k + ones][other] += dp[k][mask];
					if (new_dp[k + ones][other] >= MOD) new_dp[k + ones][other] -= MOD;
				}
			}
		}
		dp.swap(new_dp);
	}
	int res = 0;
	for (int mask : masks) {
		res = (1LL * res + dp[K][mask]) % MOD;
	}
	cout << res << '\n';
	return 0;
}
